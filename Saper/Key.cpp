#include "Key.h"

Key::Keys Key::GetKey()
{
    int key = _getch();
    if (key == Keys::ArrowDown) {
        return Keys::ArrowDown;
    }

    if (key == Keys::ArrowUp) {
        return Keys::ArrowUp;
    }

    if (key == Keys::ArrowLeft) {
        return Keys::ArrowLeft;
    }

    if (key == Keys::ArrowRight) {
        return Keys::ArrowRight;
    }

    if (key == Keys::Enter) {
        return Keys::Enter;
    }

    if (key == Keys::F) {
        return Keys::F;
    }

    return Keys::Undefined;
}
