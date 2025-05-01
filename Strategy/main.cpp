#include <iostream>
#include <string>
using namespace std;

class RouteStrategy {
public:
    virtual void buildRoute(string A, string B) = 0;
    virtual ~RouteStrategy() {}
};

class RoadStrategy : public RouteStrategy {
public:
    void buildRoute(string A, string B) override {
        cout << "Прокладено маршрут автомобілем з " << A << " до " << B << " по дорогах." << endl;
    }
};

class WalkingStrategy : public RouteStrategy {
public:
    void buildRoute(string A, string B) override {
        cout << "Прокладено маршрут пішки з " << A << " до " << B << "." << endl;
    }
};

class PublicTransportStrategy : public RouteStrategy {
public:
    void buildRoute(string A, string B) override {
        cout << "Прокладено маршрут громадським транспортом з " << A << " до " << B << "." << endl;
    }
};

class Navigator {
private:
    RouteStrategy* routeStrategy;

public:
    Navigator(RouteStrategy* strategy = nullptr) : routeStrategy(strategy) {}

    void setStrategy(RouteStrategy* strategy) {
        routeStrategy = strategy;
    }

    void buildRoute(string A, string B) {
        if (routeStrategy)
            routeStrategy->buildRoute(A, B);
        else
            cout << "Стратегія не встановлена!" << endl;
    }
};

int main() {
    Navigator navigator;

    RoadStrategy road;
    WalkingStrategy walk;
    PublicTransportStrategy transport;

    navigator.setStrategy(&road);
    navigator.buildRoute("Київ", "Львів");

    navigator.setStrategy(&walk);
    navigator.buildRoute("Парк", "Магазин");

    navigator.setStrategy(&transport);
    navigator.buildRoute("Вокзал", "Університет");

    return 0;
}
