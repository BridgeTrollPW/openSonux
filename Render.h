#ifndef RENDER_H
#define RENDER_H

#include <ncurses.h>
#include <string>
#include <thread>

class Render
{
private:
    bool running{true};

public:
    Render() = default;

    void loop()
    {
        std::thread([]() -> void {
            int counter = 1;
            while (true)
            {
#ifdef DEBUG
                mvaddstr(0, 50, ("refresh-counter " + std::to_string(counter)).c_str());
#endif
                refresh();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                counter++;
            }
        });
    }
};

#endif