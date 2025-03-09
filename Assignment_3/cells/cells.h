#pragma once

class Cells {
    private:
        int rows, cols;
        bool *grid;

    public:
        Cells(const char *fname, int m, int n);
        ~Cells();
        int countCells(int row, int col, int conn);
        int countBlobs(int conn);
        void print();
};