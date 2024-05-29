#ifndef SwaggerComponent_hpp
#define SwaggerComponent_hpp

#include "../dto/configs/WebConfigDto.hpp"

#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Resources.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/core/utils/ConversionUtils.hpp"

class SwaggerComponent {
public:
    /**
     *  General API docs info
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swaggerDocumentInfo)
    ([] {
        OATPP_COMPONENT(oatpp::Object<WebConfigDto>, webConfig);  // Get config component

        oatpp::swagger::DocumentInfo::Builder builder;
        string url = "http://" + webConfig->swaggerHost + ":" + std::to_string(webConfig->port);
        builder.setTitle("视频平台api")
            .setDescription("支持gb28181的视频平台——CPP后端版本")
            .setVersion("1.0") 
            .addServer("http://" + webConfig->swaggerHost + ":" + std::to_string(webConfig->port),"测试地址");
          
        return builder.build();
    }());

    /**
     *  Swagger-Ui Resources (<oatpp-examples>/lib/oatpp-swagger/res)
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources)
    ([] {
        // Make sure to specify correct full path to oatpp-swagger/res folder !!!
        return oatpp::swagger::Resources::loadResources(OATPP_SWAGGER_RES_PATH);
    }());
};

#endif /* SwaggerComponent_hpp */
