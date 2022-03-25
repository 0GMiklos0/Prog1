#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

#include <iostream>
#include <string>

using namespace Graph_lib;

struct Lines_window : Window {
    Lines_window(Point xy, int w, int h, const string& title);
private:
    Open_polyline lines;
    Button next_button;
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Button cmenu_button;
    Menu style_menu;
    Button smenu_button;

    void change(Color c) { lines.set_color(c); }
    void style_change(Line_style l) { lines.set_style(l); }

    void show_cmenu();
    void hide_cmenu();
    void hide_smenu() { style_menu.hide(); smenu_button.show(); }

    static void cb_cmenu(Address,Address);
    static void cb_solid(Address,Address);
    static void cb_dash(Address,Address);
    static void cb_dot(Address,Address);
    static void cb_smenu(Address,Address);
    static void cb_next(Address,Address);
    static void cb_quit(Address,Address);
};



void Lines_window::show_cmenu()
{
    int dy = (color_menu.selection.size()-1)*20;
    smenu_button.move(0,dy);
    for (int i = 0; i<style_menu.selection.size(); ++i)
        style_menu.selection[i].move(0,dy);
    hide_smenu();
    color_menu.show();
}

void Lines_window::hide_cmenu()
{
    color_menu.hide();
    cmenu_button.show();
    int dy = -(color_menu.selection.size()-1)*20;
    smenu_button.move(0,dy);
    for (int i = 0; i<style_menu.selection.size(); ++i)
        style_menu.selection[i].move(0,dy);
    hide_smenu();
}

void Lines_window::cb_cmenu(Address, Address pw)
{
    reference_to<Lines_window>(pw).cmenu_pressed();
}

void Lines_window::cb_solid(Address, Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dash(Address, Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_dot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
}

void Lines_window::cb_smenu(Address, Address pw)
{
    reference_to<Lines_window>(pw).smenu_pressed();
}

void Lines_window::cb_quit(Address, Address pw)
{
    reference_to<Lines_window>(pw).quit();
}

void Lines_window::quit()
{
    hide(); // FLTK idiom to delete window
}

void Lines_window::cb_next(Address, Address pw)
{
    reference_to<Lines_window>(pw).next();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point(x,y));

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

int main()
try {
    Lines_window win(Point(100,100),600,400,"lines");
    return gui_main();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "exception\n";
    return 2;
}
