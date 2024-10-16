#include "rendering_engine/uniformGroup.h"
#include "rendering_engine/entity.h"

std::shared_ptr<UniformGroup> UniformGroup::GetDefaultUniformGroup()
{
    auto group = std::make_shared<UniformGroup>();
    group->Register("transform", [](RenderingContext &renderingContext, Entity *entity) -> UniformVariant
                    { return entity->getWorldTransform(); });
    group->Register("viewMatrix", [](RenderingContext &renderingContext, Entity *entity) -> UniformVariant
                    { return renderingContext.viewMatrix; });
    group->Register("projectionMatrix", [](RenderingContext &renderingContext, Entity *entity) -> UniformVariant
                    { return renderingContext.projectionMatrix; });
    return group;
}
