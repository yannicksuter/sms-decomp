#include "RayCollider.h"
#include "ode/collision.h"

/**
 * Offset/Address/Size: 0x0 | 0x80201E90 | size: 0x12C
 */
u8 RayCollider::DoCollide(CollisionSpace* space)
{
    // ? sp34;
    // ? sp30;
    // ? sp2C;
    // ? sp28;
    // ? sp20;
    // ? sp1C;
    // ? sp18;
    // ? sp10;
    // ? spC;
    dContactGeom sp8;
    // ? *var_r5;
    int temp_r3;
    // s32 temp_r8;
    // s32 var_ctr;
    // s32 var_r6;
    // s32 var_r7;
    dxGeom* var_r3;
    // u8 temp_r0;

    temp_r3 = dCollide(m_rayID, (dxGeom*)space->m_spaceID, 4, &sp8, 0x2C); // this is fishy.. why is space converted to geom..
    m_unk_0x28 = (u8)((u32)(-temp_r3 & ~temp_r3) >> 0x1FU);
    if (m_unk_0x28 == 0)
    {
        return m_unk_0x28;
    }

    // var_r5 = &sp34;
    // var_r6 = 0;
    // var_r7 = 1;
    // var_ctr = temp_r3 - 1;
    // if (temp_r3 > 1)
    // {
    //     do
    //     {
    //         if (var_r5->unk20 < *(&sp8 + ((var_r6 * 0x2C) + 0x20)))
    //         {
    //             var_r6 = var_r7;
    //         }
    //         var_r5 += 0x2C;
    //         var_r7 += 1;
    //         var_ctr -= 1;
    //     } while (var_ctr != 0);
    // }
    // temp_r8 = var_r6 * 0x2C;
    // arg0->unkC = (f32) * (&sp8 + temp_r8);
    // arg0->unk10 = (f32) * (&spC + temp_r8);
    // arg0->unk14 = (f32) * (&sp10 + temp_r8);
    // arg0->unk18 = (f32) * (&sp18 + temp_r8);
    // arg0->unk1C = (f32) * (&sp1C + temp_r8);
    // arg0->unk20 = (f32) * (&sp20 + temp_r8);
    // arg0->unk24 = (f32) * (&sp28 + temp_r8);
    // var_r3 = *(&sp2C + temp_r8);
    // if (var_r3 == (u32)arg0->unk4)
    // {
    //     var_r3 = *(&sp30 + temp_r8);
    // }

    m_unk_0x08 = (PhysicsObject*)dGeomGetData(var_r3);
    return m_unk_0x28;
}

/**
 * Offset/Address/Size: 0x12C | 0x80201FBC | size: 0x60
 */
RayCollider::~RayCollider()
{
    dGeomDestroy(m_rayID);
}

/**
 * Offset/Address/Size: 0x18C | 0x8020201C | size: 0xA8
 */
RayCollider::RayCollider(float length, const nlVector3& pos, const nlVector3& dir)
{
    m_rayID = dCreateRay(NULL, length);
    dGeomSetData(m_rayID, 0);
    dGeomRaySet(m_rayID, pos.x, pos.y, pos.z, dir.x, dir.y, dir.z);
    dGeomSetCollideBits(m_rayID, 6);
    dGeomSetCategoryBits(m_rayID, 0);
    m_unk_0x28 = 0;
}
