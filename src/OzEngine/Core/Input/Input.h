#ifndef _INPUT_H_
#define _INPUT_H_

namespace Oz
{
    class cInput
    {
        public:
            static bool KeyPressed(KeyCodes _key);
            static bool KeyReleased(KeyCodes _key);
            static bool KeyHeld(KeyCodes _key);
            static bool MouseButtonDown(MouseCode _button);
    };
}

#endif