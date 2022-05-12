#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

using namespace Graph_lib;

int main()
{
	Point tl {100, 100};
	
	Simple_window win {tl, 600, 400, "Canvas"};
	
	Polygon poly;
	
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	
	win.attach(poly);
	
	win.wait_for_button();
}
