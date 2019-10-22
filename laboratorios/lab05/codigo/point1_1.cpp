/**
 * @file point1
 * @version 1.0
 * @author Pablo Buitrago and Miguel Ángel Correa
 * @title Point 1
 */


#include <iostream>
#include <list>
using namespace std;

/**
* A struct to represent a Coordinate*
*/
struct Coordinate{
    /*@{*/
    int x;/**<the x coordinate */
    int y;/**<the y coordinate */
    /*@}*/
    
    public:
        Coordinate(int x, int y){
            this->x = x;
            this->y = y;

        }

        Coordinate(){}

};

/**
* A struct to represent a Edge
*/
struct Edge{

    /*@{*/
    int id;/**<the id of the place */
    int weigth;/**<the distance to the place where the edge was putted in */
    /*@}*/

    Edge(int id, int weigth){
        this->id = id;
        this->weigth = weigth; 
    }

};

/**
* A struct to represent a Place
*/
struct Place{
    /*@{*/
    Coordinate coordinate;/**<the coordinate where the place is on */
    string name;/**<the name of the place */
    list<Edge> l;/**<list of places where this particular place has conection to */
    /*@}*/

    Place(string name, int x, int y){
        this->name = name;
        coordinate.x = x;
        coordinate.y = y;
    }

};



/**
* class CityMap
* brief Implementation of a CityMap
*
* details The implementations of the city map has a number of places where each place will lead to its conections
*/
class CityMap{


    int n;
    Place *p;
 
    public:
        CityMap(int n){
            this->n = n;
            p[n];
        }

    void addEdge(int v, int a, int w);
        

};


/**
* @brief It adds a conection from some place to another
* @param[v] The id of start place
* @param[a] The id of the place v is conected to
* @param[w] The distance from v to a
* @return Void
*/
void CityMap::addEdge(int v, int a, int w){
    Edge e(a, w);
    p[v].l.push_back(e);

}



int main(){


}
