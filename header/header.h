

struct size2 {
public:
    const int x, y;
    int size() const {
        return x * y;
    };
};