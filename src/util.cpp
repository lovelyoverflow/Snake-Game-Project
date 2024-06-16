#include "util.hpp"
#include "constant.hpp"
#include <sys/ioctl.h>
#include <termios.h>
#include <ncurses.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

void Util::CursorUtil_Set(int x, int y)
{
	move(x, y);
}

void Util::CursorUtil_Hide(void)
{
}

Point Util::CursorUtil_Get(void)
{
	Point cur_pos;
	getyx(stdscr, cur_pos.y, cur_pos.x);

	return cur_pos;
}

void Util::CursorUtil_Print(int x, int y, const char* str)
{
	mvprintw(y, x, str);
}

void Util::SetColorText(Color color)
{
 	wattron(stdscr, COLOR_PAIR(color));
}

bool Util::kbhit(void)
{
    static bool initflag = false;
    static const int STDIN = 0;

    if (!initflag) {
        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initflag = true;
    }

    int nbbytes;
    ioctl(STDIN, FIONREAD, &nbbytes);
    return nbbytes;
}

int Util::Get_Random(int s, int e)
{
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(s, e);

    return dis(gen);
}

std::vector<std::vector<int>> Util::readMapFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::vector<std::vector<int>> map;
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return map;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        int number;
        while (ss >> number) {
            row.push_back(number);
        }
        map.push_back(row);
    }

    file.close();
    return map;
}
