#include <vector>
#include <numeric>
#include "layers/forward_pass.h"

using namespace std;
typedef std::vector<float> vector_1d;
typedef std::vector<vector_1d> vector_2d;
typedef std::vector<vector_2d> vector_3d;
typedef std::vector<vector_3d> vector_4d;


int main() {

    vector<string> test_files = read_data_test_files("/Users/levialbuquerque/CLionProjects/semb/test.txt");
    vector<vector<int>> confusion_matrix = init_int_zero_2d_matrix(2, 2);

    float time_sum = 0;
    for (int i = 0; i < test_files.size(); i++) {
        int actual_class;
        if (test_files[i].find("negative") != std::string::npos) {
            actual_class = 0;
        } else {
            actual_class = 1;
        }

//        auto start = std::chrono::high_resolution_clock::now();
        int predicted_class = forward_pass(test_files[i]);
//        auto stop = std::chrono::high_resolution_clock::now();
//        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        confusion_matrix[actual_class][predicted_class]++;
    }

    ofstream output_file("/Users/levialbuquerque/CLionProjects/semb/cpp_classification_results_channels_31.txt");
    ostream_iterator<int> output_iterator(output_file, "\t");
    for (int i = 0; i < confusion_matrix.size(); i++) {
        copy(confusion_matrix.at(i).begin(), confusion_matrix.at(i).end(), output_iterator);
        output_file << '\n';
    }
    return 0;
}