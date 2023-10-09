//
// Created by smile on 2023/10/9.
//

#include <vector>
#include <numeric>

#if defined(__cpp_lib_parallel_algorithm)
    #include <execution>
#else
    #include <algorithm>
#endif

class Solution {
public:
    static std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>> &img) {
#if defined(__cpp_lib_parallel_algorithm)
        return imageSmootherParallelMethod(img);
#else
        return imageSmootherSeqMethod(img);
#endif
    }

#if defined(__cpp_lib_parallel_algorithm)
    //  并行化方案
    static std::vector<std::vector<int>> imageSmootherParallelMethod(std::vector<std::vector<int>> &img) {
        auto ans = std::vector<std::vector<int>>(img.size(), std::vector<int>(img.front().size()));

        std::vector<size_t> imgI(img.size());
        std::iota(imgI.begin(), imgI.end(), 0);
        std::for_each(std::execution::par_unseq, imgI.begin(), imgI.end(), [&img, &ans](auto &i) {
                          std::vector<size_t> imgJ(img[i].size());
                          std::iota(imgJ.begin(), imgJ.end(), 0);
                          std::for_each(std::execution::par_unseq, imgJ.begin(), imgJ.end(), [&img, &i, &ans](auto &j) {
                              ans[i][j] = get3x3FilterVal(i, j, img);
                          });
                      }
        );
        return std::move(ans);
    }
#endif

    // 序列遍历方案
    static std::vector<std::vector<int>> imageSmootherSeqMethod(std::vector<std::vector<int>> &img) {
        auto ans = std::vector<std::vector<int>>(img.size(), std::vector<int>(img.front().size()));
        for (size_t i = 0; i < img.size(); i++) {
            for (size_t j = 0; j < img.front().size(); ++j) {
                // 3 * 3 filter
                ans[i][j] = get3x3FilterVal(i, j, img);
            }
        }
        return ans;
    }

    static int get3x3FilterVal(size_t pointX, size_t pointY, const std::vector<std::vector<int>> &img) {
        int availPoint = 0;
        int sum = 0;
        for (size_t i = (pointX == 0 ? pointX : pointX - 1);
             i <= (pointX == img.size() - 1 ? pointX : pointX + 1); ++i) {
            for (size_t j = (pointY == 0 ? pointY : pointY - 1);
                 j <= (pointY == img.front().size() - 1 ? pointY : pointY + 1); ++j) {
                availPoint++;
                sum += img[i][j];
            }
        }
        return sum / availPoint;
    }


};