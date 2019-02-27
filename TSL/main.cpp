#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;



template<class T>
class Series {
private:
    vector<T> data_;
public:
    Series() : data_({}) {}
    Series(vector<T> data) : data_(data) {}
    Series(const Series& mSeries) : data_(mSeries.data) {}
    friend ostream& operator<<(ostream& os, const Series<T>& series) {
        for (auto item : series.data_) {
            os << item << ' ';
        }
        os << '\n';
        return os;
    }
    void prettyPrint() {
        // setw -- set width for one element
        cout << fixed << setprecision(6);
        for (auto i : data_) {
            cout << setfill('#') << setw(5) << i;
        }
    }
    T firstDiff(const int id);

};


template<class T>
T Series<T>::firstDiff(const int id) {
    if (data_.size() > 1 && id > 0 && id < data_.size()) {
        return data_[id] - data_[id - 1];
    }
    return -1; // invalid value
}


int main()
{
    vector<double> vec{4.12345, 5.123, 10.1239, 8.12355, 9};
    Series<double> s1(vec);
    s1.prettyPrint();
    return 0;
}
