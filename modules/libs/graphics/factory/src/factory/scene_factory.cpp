#include "factory/scene_factory.h"

#include <factory/lighting_factory.h>
#include <factory/render_object_factory.h>

namespace ifx{

SceneFactory::SceneFactory(){

}

SceneFactory::~SceneFactory(){

}

Scene* SceneFactory::CreateScene(Camera* camera){
    return CreateNanosuitGuy(camera);
    //return CreateAsteroidField(camera);
}

Scene* SceneFactory::CreateNanosuitGuy(Camera* camera){
    camera->moveTo(glm::vec3(-0.2f, 0.1f, 0.0f));

    RenderObjectFactory render_object_factory;
    LightingFactory lighting_factory;

    std::vector<RenderObject*> render_objects;
    render_objects.push_back(render_object_factory.CreateNanosuitObject());

    LightGroup* group_light = lighting_factory.createGroupLight(camera);

    Scene* scene = new Scene(render_objects,
                             group_light, camera);

    return scene;
}

Scene* SceneFactory::CreateAsteroidField(Camera* camera){
    camera->moveTo(glm::vec3(-0.2f, 0.1f, 0.0f));

    RenderObjectFactory render_object_factory;
    LightingFactory lighting_factory;

    std::vector<RenderObject*> render_objects;
    render_objects.push_back(render_object_factory.CreateAsteroidField());
    render_objects.push_back(render_object_factory.CreateAsteroid());

    LightGroup* group_light = lighting_factory.createGroupLight(camera);

    Scene* scene = new Scene(render_objects,
                             group_light, camera);

    return scene;
}

}