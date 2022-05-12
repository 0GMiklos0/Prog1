#include "./GUI/Graph.h"
#include "./GUI/Simple_window.h"

#include <iostream>
#include <string>

using namespace Graph_lib;

int main()
	try {
		Point t1 {300, 50};
		Simple_window win{t1, 1000, 800, "My window"};
		win.wait_for_button();
		
		int x_size=800;
		int y_size=800;
		Lines grid;
		
		for(int i=0;i<800;i+=100)
		{
			grid.add(Point(i, 0), Point(i, y_size));
			grid.add(Point(0, i), Point(x_size, i));
		}
		
		win.attach(grid);
		win.wait_for_button();
		
		for(int i=0; i<700; i+=100)
		{
			Rectangle r{Point{i, i}, i+100, i+100};
			r.set_fill_color(Color::red);
			win.attach(r);
		}
		
		Image i {Point{0, 0},"GUI/badge.jpg"};
		i.set_mask(Point{0, 0}, 200, 200);
		win.attach(i);
		win.wait_for_button();
		
		Image img {Point{0, 0}, "GUI/badge.jpg"};
		int index = 0;
		while(index<4)
		{
			index++;
			img.set_mask(Point{index*200, index*100}, 100, 100);
			win.attach(img);
			win.wait_for_button();
		}
		
	} catch (exception& e) {
		cerr<<"exception: "<<e.what()<<endl;
		return 1;
	} catch (...) {
		cerr<<"exception\n";
		return 2;
	}
