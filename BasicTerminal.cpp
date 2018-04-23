//
// Created by kvk1920 on 16.04.18.
//

#include <termios.h>
#include "BasicTerminal.h"

namespace BasicTerminalUtilities {

enum class terminal_state_t : bool { keypress_mode, standart_mode };

static terminal_state_t terminal_state = terminal_state_t ::standart_mode;

static termios stored_settings;

inline void SetKeypressMode(void) {
    if (terminal_state != terminal_state_t::keypress_mode) {
        termios new_settings;
        tcgetattr(0, &stored_settings);
        new_settings = stored_settings;
        new_settings.c_lflag &= (~ICANON & ~ECHO);
        new_settings.c_cc[VTIME] = 0;
        new_settings.c_cc[VMIN] = 1;
        tcsetattr(0, TCSANOW, &new_settings);
        terminal_state = terminal_state_t::keypress_mode;
    }
}

inline void SetStandartMode(void) {
    if (terminal_state != terminal_state_t::standart_mode) {
        tcsetattr(0, TCSANOW, &stored_settings);
        terminal_state = terminal_state_t::standart_mode;
    }
}

}