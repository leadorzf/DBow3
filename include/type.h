// #ifndef __D_T_TYPE__
// #define __D_T_TYPE__
#pragma once

constexpr int DescLength = 64;

typedef struct
{
    unsigned char data[DescLength];
} TDescriptor;

inline std::vector<TDescriptor> to_uchar_descriptor_vector(const std::vector<cv::Mat> &desc_mat_vector)
{
    std::vector<TDescriptor> desc_vector;
    TDescriptor temp;
    for (const auto &desc_mat : desc_mat_vector)
    {
        for (int j = 0; j < desc_mat.rows; j++)
        {
            memcpy(temp.data, (unsigned char *)desc_mat.row(j).data, DescLength);
            desc_vector.push_back(temp);
        }
    }

    return desc_vector;
}

inline std::vector<TDescriptor> to_uchar_descriptor_vector(const cv::Mat &desc_mat)
{
    std::vector<TDescriptor> desc_vector;
    desc_vector.reserve(desc_mat.rows);
    TDescriptor temp;
    for (int j = 0; j < desc_mat.rows; j++)
    {
        memcpy(temp.data, (unsigned char *)desc_mat.row(j).data, DescLength);
        desc_vector.push_back(temp);
    }

    return desc_vector;
}

// #endif
