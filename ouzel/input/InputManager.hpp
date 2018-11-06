// Copyright 2015-2018 Elviss Strazdins. All rights reserved.

#pragma once

#include <memory>
#include <mutex>
#include <vector>
#include <unordered_map>
#include "input/InputSystem.hpp"
#include "math/Vector2.hpp"

namespace ouzel
{
    namespace input
    {
        class Controller;
        class Keyboard;
        class Gamepad;
        class Mouse;
        class Touchpad;

        class InputManager final: public InputSystem::EventHandler
        {
        public:
            InputManager();
            InputManager(const InputManager&) = delete;
            InputManager& operator=(const InputManager&) = delete;

            InputManager(InputManager&&) = delete;
            InputManager& operator=(InputManager&&) = delete;

            void update();
            InputSystem* getInputSystem() const { return inputSystem.get(); }

            const std::vector<Controller*>& getControllers() const { return controllers; }
            Keyboard* getKeyboard() const { return keyboard; }
            Mouse* getMouse() const { return mouse; }
            Touchpad* getTouchpad() const { return touchpad; }

            void startDeviceDiscovery();
            void stopDeviceDiscovery();

            void showVirtualKeyboard();
            void hideVirtualKeyboard();

        private:
            bool handleEvent(const InputSystem::Event& event) override;

            std::unique_ptr<InputSystem> inputSystem;
            Keyboard* keyboard = nullptr;
            Mouse* mouse = nullptr;
            Touchpad* touchpad = nullptr;

            std::unordered_map<uint32_t, std::unique_ptr<Controller>> controllerMap;
            std::vector<Controller*> controllers;

            bool discovering = false;
        };
    } // namespace input
} // namespace ouzel
