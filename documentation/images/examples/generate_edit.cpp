#include "liboai.h"

using namespace liboai;

int main() {
  OpenAI oai;
  if (oai.auth.SetKeyEnv("OPENAI_API_KEY")) {
    try {
      // call async method; returns a future
      Response response = oai.Image->create_edit(
        "C:/some/folder/otter.png",
        "A cute baby sea otter wearing a beret",
        "C:/some/folder/mask.png"
      );

      // print some response data
      std::cout << response["data"][0]["url"].get<std::string>() << std::endl;
    }
    catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
}
