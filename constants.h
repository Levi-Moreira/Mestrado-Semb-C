//
// Created by Levi Albuquerque on 05/11/19.
//

#ifndef SEMB_CONSTANTS_H
#define SEMB_CONSTANTS_H
#define CHANNELS 31
#define CHANNELS_2 false
#define CHANNELS_18 false
#define CHANNELS_31 true

#define SCALE_MIN -10.0
#define SCALE_MAX 10.0
#define SAMPLES_PER_FILE 1000
#define KERNEL_W 10
#define KERNEL_H 1
#define KERNEL_PADDING 0
#define BATCH_EPSLON 0.001
#define POOL_STRIDE_H 1
#define POOL_STRIDE_W 2
#define POOL_KERNEL_H 1
#define POOL_KERNEL_W 2
#define CONV_STRIDE 1

#define CONV1_KERNEL_NUMBER  8
#define CONV2_KERNEL_NUMBER  16
#define CONV3_KERNEL_NUMBER  32
#define CONV4_KERNEL_NUMBER  64

#define FC1_FLATTEN_SIZE 3456
#define HIDDEN_LAYER__SIZE_W 50
#define HIDDEN_LAYER__SIZE_H 1
#define OUTPUT_LAYER__SIZE_H 1

#define CONV_1_OUTPUT_SIZE 991
#define CONV_2_INPUT_SIZE 495
#define CONV_2_OUTPUT_SIZE 486
#define CONV_3_INPUT_SIZE 243
#define CONV_3_OUTPUT_SIZE 234

#define CONV_4_INPUT_SIZE 117
#define CONV_4_OUTPUT_SIZE 108
#define FC1_INPUT_SIZE 54


#if CHANNELS_2
    #define W1_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_conv2d_1_weights.npy"
    #define BIAS1_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_conv2d_1_bias.npy"

    #define W2_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_conv2d_2_weights.npy"
    #define BIAS2_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_conv2d_2_bias.npy"
    #define GAMMA_1 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_1_gamma.npy"
    #define BETA_1 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_1_beta.npy"
    #define MEAN_1 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_1_mean.npy"
    #define VARIANCE_1 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_1_variance.npy"

    #define W3_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_conv2d_3_weights.npy"
    #define BIAS3_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_conv2d_3_bias.npy"
    #define GAMMA_2 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_2_gamma.npy"
    #define BETA_2 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_2_beta.npy"
    #define MEAN_2 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_2_mean.npy"
    #define VARIANCE_2 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_2_variance.npy"

    #define W4_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_conv2d_4_weights.npy"
    #define BIAS4_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_conv2d_4_bias.npy"
    #define GAMMA_3 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_3_gamma.npy"
    #define BETA_3 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_3_beta.npy"
    #define MEAN_3 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_3_mean.npy"
    #define VARIANCE_3 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_3_variance.npy"


    #define W5_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_dense_1_weights.npy"
    #define BIAS5_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_dense_1_bias.npy"
    #define GAMMA_4 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_4_gamma.npy"
    #define BETA_4 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_4_beta.npy"
    #define MEAN_4 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_4_mean.npy"
    #define VARIANCE_4 "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_batch_normalization_4_variance.npy"

    #define W6_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_dense_2_weights.npy"
    #define BIAS6_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_2.h5_dense_2_bias.npy"
#endif

#if CHANNELS_18
    #define W1_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_conv2d_1_weights.npy"
    #define BIAS1_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_conv2d_1_bias.npy"

    #define W2_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_conv2d_2_weights.npy"
    #define BIAS2_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_conv2d_2_bias.npy"
    #define GAMMA_1 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_1_gamma.npy"
    #define BETA_1 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_1_beta.npy"
    #define MEAN_1 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_1_mean.npy"
    #define VARIANCE_1 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_1_variance.npy"

    #define W3_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_conv2d_3_weights.npy"
    #define BIAS3_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_conv2d_3_bias.npy"
    #define GAMMA_2 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_2_gamma.npy"
    #define BETA_2 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_2_beta.npy"
    #define MEAN_2 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_2_mean.npy"
    #define VARIANCE_2 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_2_variance.npy"

    #define W4_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_conv2d_4_weights.npy"
    #define BIAS4_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_conv2d_4_bias.npy"
    #define GAMMA_3 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_3_gamma.npy"
    #define BETA_3 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_3_beta.npy"
    #define MEAN_3 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_3_mean.npy"
    #define VARIANCE_3 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_3_variance.npy"


    #define W5_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_dense_1_weights.npy"
    #define BIAS5_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_dense_1_bias.npy"
    #define GAMMA_4 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_4_gamma.npy"
    #define BETA_4 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_4_beta.npy"
    #define MEAN_4 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_4_mean.npy"
    #define VARIANCE_4 "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_batch_normalization_4_variance.npy"

    #define W6_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_dense_2_weights.npy"
    #define BIAS6_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_18.h5_dense_2_bias.npy"
#endif


#if CHANNELS_31
#define W1_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_conv2d_1_weights.npy"
    #define BIAS1_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_conv2d_1_bias.npy"

    #define W2_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_conv2d_2_weights.npy"
    #define BIAS2_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_conv2d_2_bias.npy"
    #define GAMMA_1 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_1_gamma.npy"
    #define BETA_1 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_1_beta.npy"
    #define MEAN_1 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_1_mean.npy"
    #define VARIANCE_1 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_1_variance.npy"

    #define W3_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_conv2d_3_weights.npy"
    #define BIAS3_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_conv2d_3_bias.npy"
    #define GAMMA_2 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_2_gamma.npy"
    #define BETA_2 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_2_beta.npy"
    #define MEAN_2 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_2_mean.npy"
    #define VARIANCE_2 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_2_variance.npy"

    #define W4_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_conv2d_4_weights.npy"
    #define BIAS4_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_conv2d_4_bias.npy"
    #define GAMMA_3 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_3_gamma.npy"
    #define BETA_3 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_3_beta.npy"
    #define MEAN_3 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_3_mean.npy"
    #define VARIANCE_3 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_3_variance.npy"


    #define W5_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_dense_1_weights.npy"
    #define BIAS5_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_dense_1_bias.npy"
    #define GAMMA_4 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_4_gamma.npy"
    #define BETA_4 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_4_beta.npy"
    #define MEAN_4 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_4_mean.npy"
    #define VARIANCE_4 "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_batch_normalization_4_variance.npy"

    #define W6_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_dense_2_weights.npy"
    #define BIAS6_FILE_PATH "/Users/levialbuquerque/PycharmProjects/semb/best_model_38.h5_dense_2_bias.npy"
#endif
#endif //SEMB_CONSTANTS_H
