//
// Created by Levi Albuquerque on 05/11/19.
//

#include <vector>
#include <numeric>
#include "../data/file_loading.h"
#include "convolution.h"
#include "../data/data_manipulation.h"
#include "pooling.h"
#include "activation.h"
#include "batch_norm.h"
#include "fully_connected.h"
#include "../constants.h"

using namespace std;
typedef std::vector<float> vector_1d;
typedef std::vector<vector_1d> vector_2d;
typedef std::vector<vector_2d> vector_3d;
typedef std::vector<vector_3d> vector_4d;


int forward_pass(const string &filename) {
    vector_2d INPUT_DATA = read_data_from_file_with_comma(filename, CHANNELS);
    INPUT_DATA = scale_matrix(INPUT_DATA);
    INPUT_DATA = min_max_scale_matrix(INPUT_DATA, SCALE_MIN, SCALE_MAX);
    INPUT_DATA = transpose(INPUT_DATA, SAMPLES_PER_FILE, CHANNELS);
    vector_4d input = convert_to_4d(INPUT_DATA);

    // CONV1

    vector_4d WEIGHTS = read_4d_matrix(W1_FILE_PATH, KERNEL_H, KERNEL_W, CHANNELS, CONV1_KERNEL_NUMBER, CONV1_KERNEL_NUMBER * CHANNELS * KERNEL_W * KERNEL_H);
    vector_4d BIAS = read_4d_matrix(BIAS1_FILE_PATH, 1, 1, 1, CONV1_KERNEL_NUMBER, CONV1_KERNEL_NUMBER);
    vector_4d RESULT_CONV = convolution(input, 1, 1, SAMPLES_PER_FILE, CHANNELS, WEIGHTS, BIAS, KERNEL_H, KERNEL_W, CONV1_KERNEL_NUMBER, CONV_STRIDE, KERNEL_PADDING);
    vector_4d RESULT_RELU = relu(RESULT_CONV, 1, 1, CONV_1_OUTPUT_SIZE, CONV1_KERNEL_NUMBER);
    vector_4d RESULT_POOL = maxpool(RESULT_RELU, 1, 1, CONV_1_OUTPUT_SIZE, CONV1_KERNEL_NUMBER, POOL_KERNEL_H, POOL_KERNEL_W, POOL_STRIDE_H, POOL_STRIDE_W);

    // CONV2

    WEIGHTS = read_4d_matrix(W2_FILE_PATH, KERNEL_H, KERNEL_W, CONV1_KERNEL_NUMBER, CONV2_KERNEL_NUMBER, KERNEL_H * KERNEL_W * CONV1_KERNEL_NUMBER * CONV2_KERNEL_NUMBER);
    BIAS = read_4d_matrix(BIAS2_FILE_PATH, 1, 1, 1, CONV2_KERNEL_NUMBER, CONV2_KERNEL_NUMBER);
    RESULT_CONV = convolution(RESULT_POOL, 1, 1, CONV_2_INPUT_SIZE, CONV1_KERNEL_NUMBER, WEIGHTS, BIAS, KERNEL_H, KERNEL_W, CONV2_KERNEL_NUMBER, CONV_STRIDE, KERNEL_PADDING);
    RESULT_RELU = relu(RESULT_CONV, 1, 1, CONV_2_OUTPUT_SIZE, CONV2_KERNEL_NUMBER);
    vector_1d GAMMA = read_data_from_file_with_new_line(GAMMA_1, CONV2_KERNEL_NUMBER);
    vector_1d BETA = read_data_from_file_with_new_line(BETA_1, CONV2_KERNEL_NUMBER);
    vector_1d MEAN = read_data_from_file_with_new_line(MEAN_1, CONV2_KERNEL_NUMBER);
    vector_1d VARIANCE = read_data_from_file_with_new_line(VARIANCE_1, CONV2_KERNEL_NUMBER);
    vector_4d RESULT_BATCH = batch_norm_4d(RESULT_RELU, GAMMA, BETA, MEAN, VARIANCE, BATCH_EPSLON, 1, 1, CONV_2_OUTPUT_SIZE, CONV2_KERNEL_NUMBER);
    RESULT_POOL = maxpool(RESULT_BATCH, 1, 1, CONV_2_OUTPUT_SIZE, CONV2_KERNEL_NUMBER, POOL_KERNEL_H, POOL_KERNEL_W, POOL_STRIDE_H, POOL_STRIDE_W);



    // CONV3

    WEIGHTS = read_4d_matrix(W3_FILE_PATH, KERNEL_H, KERNEL_W, CONV2_KERNEL_NUMBER, CONV3_KERNEL_NUMBER, KERNEL_H * KERNEL_W * CONV2_KERNEL_NUMBER * CONV3_KERNEL_NUMBER);
    BIAS = read_4d_matrix(BIAS3_FILE_PATH, 1, 1, 1, CONV3_KERNEL_NUMBER, CONV3_KERNEL_NUMBER);


    RESULT_CONV = convolution(RESULT_POOL, 1, 1, CONV_3_INPUT_SIZE, CONV2_KERNEL_NUMBER, WEIGHTS, BIAS, KERNEL_H, KERNEL_W, CONV3_KERNEL_NUMBER, CONV_STRIDE, KERNEL_PADDING);

    RESULT_RELU = relu(RESULT_CONV, 1, 1, CONV_3_OUTPUT_SIZE, CONV3_KERNEL_NUMBER);
    GAMMA = read_data_from_file_with_new_line(GAMMA_2, CONV3_KERNEL_NUMBER);
    BETA = read_data_from_file_with_new_line(BETA_2, CONV3_KERNEL_NUMBER);
    MEAN = read_data_from_file_with_new_line(MEAN_2, CONV3_KERNEL_NUMBER);
    VARIANCE = read_data_from_file_with_new_line(VARIANCE_2, CONV3_KERNEL_NUMBER);
    RESULT_BATCH = batch_norm_4d(RESULT_RELU, GAMMA, BETA, MEAN, VARIANCE, BATCH_EPSLON, 1, 1, CONV_3_OUTPUT_SIZE, CONV3_KERNEL_NUMBER);
    RESULT_POOL = maxpool(RESULT_BATCH, 1, 1, CONV_3_OUTPUT_SIZE, CONV3_KERNEL_NUMBER, POOL_KERNEL_H, POOL_KERNEL_W, POOL_STRIDE_H, POOL_STRIDE_W);


    // CONV4
    WEIGHTS = read_4d_matrix(W4_FILE_PATH, KERNEL_H, KERNEL_W, CONV3_KERNEL_NUMBER, CONV4_KERNEL_NUMBER, KERNEL_H * KERNEL_W * CONV3_KERNEL_NUMBER * CONV4_KERNEL_NUMBER);
    BIAS = read_4d_matrix(BIAS4_FILE_PATH, 1, 1, 1, CONV4_KERNEL_NUMBER, CONV4_KERNEL_NUMBER);
    RESULT_CONV = convolution(RESULT_POOL, 1, 1, CONV_4_INPUT_SIZE, CONV3_KERNEL_NUMBER, WEIGHTS, BIAS, KERNEL_H, KERNEL_W, CONV4_KERNEL_NUMBER, CONV_STRIDE, KERNEL_PADDING);
    RESULT_RELU = relu(RESULT_CONV, 1, 1, CONV_4_OUTPUT_SIZE, CONV4_KERNEL_NUMBER);
    GAMMA = read_data_from_file_with_new_line(GAMMA_3, CONV4_KERNEL_NUMBER);
    BETA = read_data_from_file_with_new_line(BETA_3, CONV4_KERNEL_NUMBER);
    MEAN = read_data_from_file_with_new_line(MEAN_3, CONV4_KERNEL_NUMBER);
    VARIANCE = read_data_from_file_with_new_line(VARIANCE_3, CONV4_KERNEL_NUMBER);
    RESULT_BATCH = batch_norm_4d(RESULT_RELU, GAMMA, BETA, MEAN, VARIANCE, BATCH_EPSLON, 1, 1, CONV_4_OUTPUT_SIZE, CONV4_KERNEL_NUMBER);
    RESULT_POOL = maxpool(RESULT_BATCH, 1, 1, CONV_4_OUTPUT_SIZE, CONV4_KERNEL_NUMBER, POOL_KERNEL_H, POOL_KERNEL_W, POOL_STRIDE_H, POOL_STRIDE_W);




    //FC1
    vector_2d X6 = convert_to_2d(RESULT_POOL, 1, 1, FC1_INPUT_SIZE, CONV4_KERNEL_NUMBER, 1, FC1_FLATTEN_SIZE);

    vector_2d WEIGHTS_2D = read_2d_matrix(W5_FILE_PATH, FC1_FLATTEN_SIZE, HIDDEN_LAYER__SIZE_W, FC1_FLATTEN_SIZE * HIDDEN_LAYER__SIZE_W);
    vector_2d BIAS_2D = read_2d_matrix(BIAS5_FILE_PATH, HIDDEN_LAYER__SIZE_W, 1, HIDDEN_LAYER__SIZE_W);
    vector_2d OUTPUT_FC_LAYER = fc_forward(X6, WEIGHTS_2D, BIAS_2D, 1, HIDDEN_LAYER__SIZE_W, FC1_FLATTEN_SIZE);
    OUTPUT_FC_LAYER = relu_2d(OUTPUT_FC_LAYER, 1, HIDDEN_LAYER__SIZE_W);
    GAMMA = read_data_from_file_with_new_line(GAMMA_4, HIDDEN_LAYER__SIZE_W);
    BETA = read_data_from_file_with_new_line(BETA_4, HIDDEN_LAYER__SIZE_W);
    MEAN = read_data_from_file_with_new_line(MEAN_4, HIDDEN_LAYER__SIZE_W);
    VARIANCE = read_data_from_file_with_new_line(VARIANCE_4, HIDDEN_LAYER__SIZE_W);
    OUTPUT_FC_LAYER = batch_norm_2d(OUTPUT_FC_LAYER, GAMMA, BETA, MEAN, VARIANCE, BATCH_EPSLON, HIDDEN_LAYER__SIZE_H, HIDDEN_LAYER__SIZE_W);
//    auto start = std::chrono::high_resolution_clock::now();



    //FC2
    WEIGHTS_2D = read_2d_matrix(W6_FILE_PATH, HIDDEN_LAYER__SIZE_W, 1, HIDDEN_LAYER__SIZE_W);
    BIAS_2D = read_2d_matrix(BIAS6_FILE_PATH, 1, 1, 1);
    OUTPUT_FC_LAYER = fc_forward(OUTPUT_FC_LAYER, WEIGHTS_2D, BIAS_2D, HIDDEN_LAYER__SIZE_H, OUTPUT_LAYER__SIZE_H, HIDDEN_LAYER__SIZE_W);
    float output = sigmoid(OUTPUT_FC_LAYER[0][0]);

//    auto stop = std::chrono::high_resolution_clock::now();
//    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    return output > 0.5 ? 1 : 0;
}