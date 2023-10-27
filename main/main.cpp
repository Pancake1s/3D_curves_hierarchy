#include "Curve.h"

int main() {
    srand(time(NULL));

    //creating the first container with 10 elements
    int q = 10;
    vector<Curve*> first_container;
    for (int i = 0; i < q; i++)
    {
        first_container.push_back(Change(1 + rand() % 3));
    }

    double t = M_PI / 4;
    cout << "t = " << t << "\n";

    //output of coordinates of the points and the derivatives of all curves in the container at t=PI/4.
    cout << "<<The first container>>" << "\n";
    for (int i = 0; i < q; i++)
    {
        first_container[i]->Print(t);
    }

    //creating and filling the second container
    vector<Curve*> second_container;
    for (int i = 0; i < q; i++)
    {
        if (typeid(*first_container[i]) == typeid(Circle)) {
            second_container.push_back(first_container[i]);
        }
    }
    cout << "\n\n";

    //displaying the second container
    cout << "<<The second container>>" << "\n";
    for (int i = 0; i < second_container.size(); i++)
    {
        second_container[i]->Print(t);
    }
    cout << "\n\n";

    //sorting the second container
    Sort(second_container);

    //displaying the second container and calculating the sum of radii
    cout << "<<Sorted second container>>" << "\n";
    double sum = 0;
    for (int i = 0; i < second_container.size(); i++)
    {
        second_container[i]->Print(t);
        sum += second_container[i]->GetRadius();
    }
    cout << "Sum of radii = " << sum << "\n";

    //clearing memory
    for (int i = 0; i < q; i++)
    {
        delete first_container[i];
    }
    first_container.clear();
    second_container.clear();

    return 0;
}