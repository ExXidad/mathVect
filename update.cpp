class Vector {
private:
    std::vector<double> data;
    double data[5];

public:
    const std::vector<double> &getData() const {
        return data;
    Vector(const double *newData) {
        setData(newData);
    }

    void setData(const std::vector<double> &data) {
        Vector::data = data;
    void setData(const double *newData) {
        for (int i = 0; i < 5; ++i) {
            data[i] = newData[i];
        }
    }

    Vector(std::vector<double> newDat) {
        data = newDat;
    };

    Vector add(const Vector &anotherVect) {
        if (data.size() != anotherVect.data.size()) {
            throw std::invalid_argument("Wrond dimensions");
        };
    const double *getData() {
        return data;
    }

        std::vector<double> tmp(data.size(), 0);
        for (int i = 0; i < data.size(); ++i) {
            tmp[i] = data[i] + anotherVect.data[i];
    Vector add(Vector anotherVector) {
        double tmp[5]{0, 0, 0, 0, 0};
        for (int i = 0; i < 5; ++i) {
            tmp[i] = data[i] + anotherVector.data[i];
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
    Vector subtract(Vector anotherVector) {
        double tmp[5]{0, 0, 0, 0, 0};
        for (int i = 0; i < 5; ++i) {
            tmp[i] = data[i] - anotherVector.data[i];
        }

        return Vector(tmp);
    }

    double scalarProduct(const Vector &anotherVect) {
        if (data.size() != anotherVect.data.size()) {
            throw std::invalid_argument("Wrond dimensions");
        };

    double scalarProduct(Vector anotherVector) {
        double tmp = 0;
        for (int i = 0; i < data.size(); ++i) {
            tmp += data[i] * anotherVect.data[i];
        for (int i = 0; i < 5; ++i) {
            tmp += data[i] * anotherVector.data[i];
        }

        return tmp;
    }

    void outVect() {
        for (const auto &item : data) {
            std::cout << item << " ";
    void outVector() {
        for (double i : data) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    };
    }
};

int main() {
    Vector a({1, 2, 3, 4, 5}), b({3, 5, 2, 1, 8});
class Matrix {
private:
    double data[3][3];

public:
    Matrix(const double newData[3][3]) {
        setData(newData);
    }

    void setData(const double newData[3][3]) {
        for (int j = 0; j < 3; ++j)
            for (int i = 0; i < 3; ++i) {
                data[i][j] = newData[i][j];
            }
    }

    Matrix add(Matrix anotherMatrix) {
        double tmp[3][3];
        for (int j = 0; j < 3; ++j)
            for (int i = 0; i < 3; ++i) {
                tmp[i][j] = data[i][j] + anotherMatrix.data[i][j];
            }
        return Matrix(tmp);
    }

    Matrix subtract(Matrix anotherMatrix) {
        double tmp[3][3];
        for (int j = 0; j < 3; ++j)
            for (int i = 0; i < 3; ++i) {
                tmp[i][j] = data[i][j] - anotherMatrix.data[i][j];
            }
        return Matrix(tmp);
    }

    double scalarProduct(Matrix anotherMatrix) {
        double tmp = 0;
        for (int j = 0; j < 3; ++j)
            for (int i = 0; i < 3; ++i) {
                tmp += data[i][j] * anotherMatrix.data[i][j];
            }
        return tmp;
    }

    void outMatrix() {
        for (int j = 0; j < 3; ++j) {
            std::cout << "| ";
            for (int i = 0; i < 3; ++i) {
                std::cout << data[j][i] << " ";
            }
            std::cout << "|";
            std::cout << std::endl;
        }
    }
};

    a.outVect();
    b.outVect();
    a.add(b).outVect();
    a.subtract(b).outVect();
    std::cout << a.scalarProduct(b) << std::endl;

int main() {
    auto *tmp1 = new double[5]{1, 2, 3, 4, 5}, *tmp2 = new double[5]{1, 2, 3, 4, 5};
    Vector x(tmp1), y(tmp2);
    std::cout << "x" << std::endl;
    x.outVector();
    std::cout << "y" << std::endl;
    y.outVector();
    std::cout << "sum" << std::endl;
    x.add(y).outVector();
    std::cout << "subtract" << std::endl;
    x.subtract(y).outVector();
    std::cout << "scalar product" << std::endl;
    std::cout << x.scalarProduct(y) << std::endl;

    double tmp3[3][3]{{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}};
    double tmp4[3][3]{{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}};

    Matrix z(tmp3), h(tmp4);
    std::cout << "z" << std::endl;
    z.outMatrix();
    std::cout << "h" << std::endl;
    h.outMatrix();
    std::cout << "sum" << std::endl;
    z.add(h).outMatrix();
    std::cout << "subtract" << std::endl;
    z.subtract(h).outMatrix();
    std::cout << "scalar product" << std::endl;
    std::cout << z.scalarProduct(h) << std::endl;

    return 0;
}
