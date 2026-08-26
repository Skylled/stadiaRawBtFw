// 60102192  FUN_60102192  size=590 bytes
// --- callers ---
//   60090568 FUN_60090568
//   60102192 FUN_60102192
// --- callees ---
//   60102154 FUN_60102154
//   60102122 FUN_60102122
//   60102192 FUN_60102192


void FUN_60102192(undefined4 *param_1,uint param_2,uint param_3,code *param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 *local_34;
  
  do {
    if ((((uint)param_1 & 3) == 0) && ((param_3 & 3) == 0)) {
      iVar6 = 0;
      if (param_3 != 4) {
        iVar6 = 1;
      }
    }
    else {
      iVar6 = 2;
    }
    puVar11 = (undefined4 *)((int)param_1 + param_3);
    if (param_2 < 7) {
      do {
        puVar7 = puVar11;
        if ((undefined4 *)(param_3 * param_2 + (int)param_1) <= puVar11) {
          return;
        }
        while (param_1 < puVar7) {
          puVar8 = (undefined4 *)((int)puVar7 - param_3);
          iVar2 = (*param_4)(puVar8,puVar7);
          if (iVar2 < 1) break;
          if (iVar6 == 0) {
            uVar5 = *puVar7;
            *puVar7 = *puVar8;
            *puVar8 = uVar5;
            puVar7 = puVar8;
          }
          else {
            FUN_60102122(puVar7,puVar8,param_3,iVar6);
            puVar7 = puVar8;
          }
        }
        puVar11 = (undefined4 *)((int)puVar11 + param_3);
      } while( true );
    }
    puVar7 = (undefined4 *)(param_3 * (param_2 >> 1) + (int)param_1);
    puVar8 = (undefined4 *)(param_3 * (param_2 - 1) + (int)param_1);
    if (param_2 != 7) {
      puVar3 = puVar8;
      local_34 = param_1;
      if (0x28 < param_2) {
        iVar9 = param_3 * (param_2 >> 3);
        local_34 = (undefined4 *)
                   FUN_60102154(param_1,(undefined4 *)((int)param_1 + iVar9),
                                (undefined4 *)((int)param_1 + iVar9 + iVar9),param_4);
        puVar7 = (undefined4 *)
                 FUN_60102154((int)puVar7 - iVar9,puVar7,(undefined4 *)((int)puVar7 + iVar9),param_4
                             );
        iVar2 = (int)puVar8 + iVar9 * -2;
        puVar3 = (undefined4 *)FUN_60102154(iVar2,iVar2 + iVar9,puVar8,param_4);
      }
      puVar7 = (undefined4 *)FUN_60102154(local_34,puVar7,puVar3,param_4);
    }
    if (iVar6 == 0) {
      uVar5 = *param_1;
      *param_1 = *puVar7;
      *puVar7 = uVar5;
    }
    else {
      FUN_60102122(param_1,puVar7,param_3,iVar6);
    }
    bVar1 = false;
    puVar3 = puVar8;
    local_34 = puVar11;
    for (puVar7 = puVar11; puVar7 <= puVar8; puVar7 = (undefined4 *)((int)puVar7 + param_3)) {
      iVar2 = (*param_4)(puVar7,param_1);
      puVar10 = puVar8;
      if (iVar2 < 1) {
        if (iVar2 == 0) {
          if (iVar6 == 0) {
            uVar5 = *local_34;
            *local_34 = *puVar7;
            *puVar7 = uVar5;
          }
          else {
            FUN_60102122(local_34,puVar7,param_3,iVar6);
          }
          local_34 = (undefined4 *)((int)local_34 + param_3);
          goto LAB_601022b6;
        }
      }
      else {
        while( true ) {
          iVar2 = (*param_4)(puVar10,param_1);
          puVar8 = (undefined4 *)((int)puVar10 - param_3);
          if (iVar2 < 0) break;
          if (iVar2 == 0) {
            if (iVar6 == 0) {
              uVar5 = *puVar10;
              *puVar10 = *puVar3;
              *puVar3 = uVar5;
            }
            else {
              FUN_60102122(puVar10,puVar3,param_3,iVar6);
            }
            puVar3 = (undefined4 *)((int)puVar3 - param_3);
            bVar1 = true;
          }
          puVar10 = puVar8;
          if (puVar8 < puVar7) goto LAB_6010233c;
        }
        if (iVar6 == 0) {
          uVar5 = *puVar7;
          *puVar7 = *puVar10;
          *puVar10 = uVar5;
        }
        else {
          FUN_60102122(puVar7,puVar10,param_3,iVar6);
        }
LAB_601022b6:
        bVar1 = true;
      }
    }
LAB_6010233c:
    puVar10 = (undefined4 *)(param_3 * param_2 + (int)param_1);
    if (!bVar1) {
      do {
        puVar7 = puVar11;
        if (puVar10 <= puVar11) {
          return;
        }
        while (param_1 < puVar7) {
          puVar8 = (undefined4 *)((int)puVar7 - param_3);
          iVar2 = (*param_4)(puVar8,puVar7);
          if (iVar2 < 1) break;
          if (iVar6 == 0) {
            uVar5 = *puVar7;
            *puVar7 = *puVar8;
            *puVar8 = uVar5;
            puVar7 = puVar8;
          }
          else {
            FUN_60102122(puVar7,puVar8,param_3,iVar6);
            puVar7 = puVar8;
          }
        }
        puVar11 = (undefined4 *)((int)puVar11 + param_3);
      } while( true );
    }
    uVar12 = (int)puVar7 - (int)local_34;
    uVar4 = (int)local_34 - (int)param_1;
    if ((int)uVar12 <= (int)local_34 - (int)param_1) {
      uVar4 = uVar12;
    }
    if (uVar4 != 0) {
      FUN_60102122(param_1,(int)puVar7 - uVar4,uVar4,iVar6);
    }
    param_2 = (int)puVar3 - (int)puVar8;
    uVar4 = (int)puVar10 + (-param_3 - (int)puVar3);
    if (param_2 <= uVar4) {
      uVar4 = param_2;
    }
    if (uVar4 != 0) {
      FUN_60102122(puVar7,(int)puVar10 - uVar4,uVar4,iVar6);
    }
    if (param_3 < uVar12) {
      FUN_60102192(param_1,uVar12 / param_3,param_3,param_4);
    }
    if (param_2 <= param_3) {
      return;
    }
    param_1 = (undefined4 *)((int)puVar10 - param_2);
    param_2 = param_2 / param_3;
  } while( true );
}


