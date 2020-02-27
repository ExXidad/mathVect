#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> mapDouble;

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

class Matrix {
private:
    mapDouble data;
public:
    Matrix(const mapDouble &newDat) {
        data = newDat;
    };

    void setData(const mapDouble &data) {
        Matrix::data = data;
    }

    Matrix add(const Matrix &anotherMatrix) {
        if (data[0].size() != anotherMatrix.data[0].size() || data.size() != anotherMatrix.data.size()) {
            throw std::invalid_argument("Wrond dimensions");
        };

        mapDouble tmp(data.size(), std::vector<double>(data[0].size(), 0));
        for (int j = 0; j < data.size(); ++j)
            for (int i = 0; i < data[0].size(); ++i) {
                tmp[j][i] = data.at(j).at(i) + anotherMatrix.data.at(j).at(i);
            }

        return Matrix(tmp);
    }

    Matrix subtract(const Matrix &anotherMatrix) {
        if (data[0].size() != anotherMatrix.data[0].size() || data.size() != anotherMatrix.data.size()) {
            throw std::invalid_argument("Wrond dimensions");
        };

        mapDouble tmp(data.size(), std::vector<double>(data[0].size(), 0));
        for (int j = 0; j < data.size(); ++j)
            for (int i = 0; i < data[0].size(); ++i) {
                tmp[j][i] = data.at(j).at(i) - anotherMatrix.data.at(j).at(i);
            }

        return Matrix(tmp);
    }

    double scalarProduct(const Matrix &anotherMatrix) {
        if (data[0].size() != anotherMatrix.data[0].size() || data.size() != anotherMatrix.data.size()) {
            throw std::invalid_argument("Wrond dimensions");
        };

        double tmp = 0;
        for (int j = 0; j < data.size(); ++j)
            for (int i = 0; i < data[0].size(); ++i) {
                tmp += data.at(j).at(i) * anotherMatrix.data.at(j).at(i);
            }

        return tmp;
    }

    void outMatrix() {
        for (int j = 0; j < data.size(); ++j) {
            std::cout << "| ";
            for (int i = 0; i < data[0].size(); ++i) {
                std::cout << data[j][i] << " ";
            }
            std::cout << "|";
            std::cout << std::endl;
        }
    };
};

int main() {
//    Vector a({1, 2, 3, 4, 5}), b({3, 5, 2, 1, 8});
//
//    a.outVect();
//    b.outVect();
//    a.add(b).outVect();
//    a.subtract(b).outVect();
//    std::cout << a.scalarProduct(b) << std::endl;

    Matrix myMatrix1(mapDouble{
            {1, 2, 3, 4},
            {4, 5, 6, 3},
            {5, 2, 1, 2}});

    Matrix myMatrix2(mapDouble{
            {4, 22, 13, 74},
            {4, 2,  6,  3},
            {7, 5,  3,  21}});

    std::cout << "matrix 1" << std::endl;
    myMatrix1.outMatrix();

    std::cout << "matrix 2" << std::endl;
    myMatrix2.outMatrix();

    std::cout << "matrix 1 + matrix 2" << std::endl;
    myMatrix1.add(myMatrix2).outMatrix();

    std::cout << "matrix 1 - matrix 2" << std::endl;
    myMatrix1.subtract(myMatrix2).outMatrix();

    std::cout << "matrix 1 . matrix 2" << std::endl;
    std::cout << myMatrix1.scalarProduct(myMatrix2) << std::endl;




    return 0;
}