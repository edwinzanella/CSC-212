#include <iostream>

void tower_of_hanoi(int num_disks, int source_rod, int destination_rod, int other_rod) {
    if (num_disks == 1) {
        std::cout << "Move disk 1 from tower " << source_rod << " to tower " << destination_rod << std::endl;
        return;
    }

    tower_of_hanoi(num_disks - 1, source_rod, other_rod, destination_rod);
    std::cout << "Move disk " << num_disks << " from tower " << source_rod << " to tower " << destination_rod << std::endl;
    tower_of_hanoi(num_disks - 1, other_rod, destination_rod, source_rod);
}

int main(int argc, char* argv[]) {
    int num_disks = atoi(argv[1]);
    int source_rod = atoi(argv[2]);
    int destination_rod = atoi(argv[3]);
    int other_rod = 6 - source_rod - destination_rod;

    tower_of_hanoi(num_disks, source_rod, destination_rod, other_rod);
}