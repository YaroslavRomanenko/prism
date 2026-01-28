#pragma once

#include <string>
#include <vector>

namespace sai {
    class Pipeline {
        public:
            Pipeline(const std::string& vertFilepath, const std::string& fragFilepath);
            
            static std::vector<char> readFile(const std::string& filepath);

        private:
            void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath);
    };

} // namespace sai