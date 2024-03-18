#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace sf;

struct Point {
    float x;
    float y;
};

vector<Point> points;
vector<Point> hull;

Point leftMost;
Point currentVertex;
int Index;
int nextIndex = -1;
Point nextVertex;
bool runningAlgorithm = false;
int colorFactor = 10; // to change the color of hull each time

void draw(RenderWindow &window) {
    window.clear(Color::Black);
    
    // Draw points
    CircleShape pointShape(2);
    pointShape.setFillColor(Color::White);
    for (const auto &p : points) {
        pointShape.setPosition(p.x, p.y);
        window.draw(pointShape);
    }

    // Draw hull
    ConvexShape convex;
    convex.setPointCount(hull.size());
    convex.setFillColor(Color(0+colorFactor, 0+colorFactor, 255, 50));
    colorFactor += 15; //change the colorFactor each time
		       
    for (size_t i = 0; i < hull.size(); ++i) {
        convex.setPoint(i, Vector2f(hull[i].x, hull[i].y));
    }
    window.draw(convex);

    // Draw currentVertex, leftMost and nextVertex
    CircleShape vertexShape(5);
    vertexShape.setFillColor(Color::Green);
    vertexShape.setPosition(leftMost.x, leftMost.y);
    window.draw(vertexShape);
    vertexShape.setFillColor(Color::Magenta);
    vertexShape.setPosition(currentVertex.x, currentVertex.y);
    window.draw(vertexShape);
    vertexShape.setFillColor(Color::Red);
    vertexShape.setPosition(nextVertex.x, nextVertex.y);
    window.draw(vertexShape);

    // Draw line between currentVertex and nextVertex
    Vertex line[] = {
        Vertex(Vector2f(currentVertex.x, currentVertex.y), Color::Yellow),
        Vertex(Vector2f(nextVertex.x, nextVertex.y), Color::Yellow)
    };
    window.draw(line, 2, Lines);

    // Display algorithm status message
    if (runningAlgorithm) {
        Font font;
        if (!font.loadFromFile("arial.ttf")) { // Load a font for text rendering
            cerr << "Failed to load font file." << endl;
            return;
        }
        Text text("Algorithm is running...", font, 20);
        text.setFillColor(Color::White);
        text.setPosition(10, 10);
        window.draw(text);
    }
    
    if (!runningAlgorithm) {
        Font font;
        if (!font.loadFromFile("arial.ttf")) { // Load a font for text rendering
            cerr << "Failed to load font file." << endl;
            return;
        }
        Text text("Provide Input points via mouse click...", font, 20);
        text.setFillColor(Color::White);
        text.setPosition(10, 10);
        window.draw(text);
    }


    // Display drawn elements
    window.display();
}

int main() {

    RenderWindow window(VideoMode(500, 500), "jarvis March Algorithm");
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed){
                window.close();
                cout<<"Window Closed!"<<endl;
            }

            else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                if (!runningAlgorithm) { //algorithm is not running
                    Point newPoint;
                    newPoint.x = event.mouseButton.x;
                    newPoint.y = event.mouseButton.y;
                    points.push_back(newPoint);
                }
            }
            
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                if (!runningAlgorithm && points.size() >= 3) {
                    runningAlgorithm = true;
                    // Sorting points based on x-coordinate
                    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
                        return a.x < b.x;
                    });
                    leftMost = points[0];
                    currentVertex = leftMost;
                    hull.push_back(currentVertex);
                    nextVertex = points[1];
                    Index = 2;
                }
            }
        }

        if (runningAlgorithm) {
            // Algorithm logic goes here
            Point checking = points[Index];
            Point a = {nextVertex.x - currentVertex.x, nextVertex.y - currentVertex.y};
            Point b = {checking.x - currentVertex.x, checking.y - currentVertex.y};
            float cross = a.x * b.y - a.y * b.x;

            if (cross < 0) {
                nextVertex = checking;
                nextIndex = Index;
            }

            Index++;
            if (Index == points.size()) {
                if (nextVertex.x == leftMost.x && nextVertex.y == leftMost.y) {
                    cout << "done" << endl;
                    runningAlgorithm = false;
                } else {
                    hull.push_back(nextVertex);
                    currentVertex = nextVertex;
                    Index = 0;
                    nextVertex = leftMost;
                }
            }
        }

        draw(window);
        
        // Introduce a delay (in milliseconds) between each step
        sleep(milliseconds(100)); // Adjust the duration as needed
    }

    return 0;
}
