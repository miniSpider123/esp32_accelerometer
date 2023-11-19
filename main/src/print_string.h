#pragma once

//----------------------------------------------------------------

template <typename T>
extern Print &operator<<(Print &printer, T value)
{
    printer.print(value);
    return printer;
}