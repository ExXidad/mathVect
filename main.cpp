#include <iostream>
#include <vector>

class Vector {
private:
    std::vector<double> data;
public:
    const std::vector<double> &getData() const {
        return data;
    }

    void setData(const std::vector<double> &data) {
        Vector::data = data;
    }

    Vector(std::vector<double> newDat) {
        data = newDat;
    };

    Vector add(const Vector &anotherVect) {
        if (data.size() != anotherVect.data.size()) {
            throw std::invalid_argument("Wrond dimensions");
        };

        std::vector<double> tmp(data.size(), 0);
        for (int i = 0; i < data.size(); ++i) {
            tmp[i] = data[i] + anotherVect.data[i];
        }

        return Vector(tmp);
    }

    Vector subtract(const Vector &anotherVect) {
        if (data.size() != anotherVect.data.size()) {
            throw std::invalid_argument("Wrond dimensions");
        };

        std::vector<double> tmp(data.size(), 0);
        for (int i = 0; i < data.size(); ++i) {
            tmp[i] = data[i] - anotherVect.data[i];
        }

        return Vector(tmp);
    }

    double scalarProduct(const Vector &anotherVect) {
        if (data.size() != anotherVect.data.size()) {
            throw std::invalid_argument("Wrond dimensions");
        };

        double tmp = 0;
        for (int i = 0; i < data.size(); ++i) {
            tmp += data[i] * anotherVect.data[i];
        }

        return tmp;
    }

    void outVect() {
        for (const auto &item : data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    };
};

int main() {
    Vector a({1, 2, 3, 4, 5}), b({3, 5, 2, 1, 8});

    a.outVect();
    b.outVect();
    a.add(b).outVect();
    a.subtract(b).outVect();
    std::cout << a.scalarProduct(b) << std::endl;


    return 0;
}