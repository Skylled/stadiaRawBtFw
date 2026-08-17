// 60068f88  activation_sequence__60068f88  size=344 bytes
// src: activation_sequence.cc
// --- callers ---
//   60069964 adapter__60069964
//   600691f4 adapter__600691f4
// --- callees ---
//   601016f0 FUN_601016f0
//   60068e98 FUN_60068e98
//   600d8b3a FUN_600d8b3a
//   60101b76 FUN_60101b76
//   60095700 FUN_60095700
//   6010165c FUN_6010165c
//   60068f04 activation_sequence__60068f04
//   6009582c FUN_6009582c
//   60101ba2 FUN_60101ba2
//   6006a5c8 gatt_server__6006a5c8
//   60095778 FUN_60095778


/* src: activation_sequence.cc */

void activation_sequence__60068f88(undefined2 *param_1,undefined4 param_2,undefined1 *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  undefined *local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  int local_a4;
  int iStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [134];
  
  if (*(int *)(param_1 + 0xaa) == 0) {
    FUN_6010165c(0x1e,PTR_s_activation_sequence_cc_600690e4,0x54,
                 PTR_s_Activation_continued_without_any_600690e0);
  }
  else {
    iStack_a0 = FUN_600d8b3a(param_2,param_1 + 2);
    if (iStack_a0 == 0) {
      local_9c = 0;
      local_b0 = PTR_s_activation_sequence_cc_600690e4;
      local_9b = 0;
      local_ac = 0x5d;
      local_a8 = local_9a;
      local_9a[0] = 0;
      local_a4 = 0x80;
      FUN_60101b76(&local_a8,PTR_s_Server_does_not_support_service_600690e8);
      uVar2 = FUN_60068e98(param_1 + 2,local_a8 + iStack_a0,local_a4 - iStack_a0);
      FUN_60101ba2(&local_a8,uVar2);
      FUN_601016f0(0x28,local_b0,local_ac,&local_a8);
    }
    else {
      *(undefined2 *)(*(int *)(iStack_a0 + 0x14) + 8) = *param_1;
      if (*(uint *)(param_1 + 0xc) < *(uint *)(iStack_a0 + 0x118)) {
        piVar8 = *(int **)(*(int *)(iStack_a0 + *(uint *)(param_1 + 0xc) * 4 + 0x18) + 4);
        iVar4 = piVar8[2];
        iVar6 = piVar8[3];
        iVar7 = piVar8[4];
        *(int *)(param_1 + 0xa0) = piVar8[1];
        *(int *)(param_1 + 0xa2) = iVar4;
        *(int *)(param_1 + 0xa4) = iVar6;
        *(int *)(param_1 + 0xa6) = iVar7;
        *(int *)(param_1 + 0xa8) = piVar8[5];
        if (*(int *)(param_1 + 0xe) == 0xffff) {
          gatt_server__6006a5c8(&local_b0);
          bVar1 = *(byte *)(piVar8 + 6);
          bVar5 = bVar1 & 2;
          if ((bVar1 & 2) != 0) {
            if ((*(byte *)((int)piVar8 + 0x19) & 4) == 0) {
              bVar5 = 1;
            }
            else {
              bVar5 = 3;
            }
            if ((int)((uint)*(byte *)((int)piVar8 + 0x19) << 0x1c) < 0) {
              bVar5 = bVar5 | 4;
            }
          }
          if ((bVar1 & 0xc) != 0) {
            if ((int)((uint)*(byte *)((int)piVar8 + 0x1a) << 0x1d) < 0) {
              bVar5 = bVar5 | 0x30;
            }
            else {
              bVar5 = bVar5 | 0x10;
            }
            if ((int)((uint)*(byte *)((int)piVar8 + 0x1a) << 0x1c) < 0) {
              bVar5 = bVar5 | 0x40;
            }
          }
          FUN_60095700(*param_1,&local_b0,bVar5);
          *param_3 = 9;
          iVar4 = 0;
        }
        else {
          iVar4 = (**(code **)(*piVar8 + 4))(piVar8,piVar8 + 1);
          gatt_server__6006a5c8(&local_b0,*(int *)(param_1 + 0xe) * 0x14 + iVar4);
          FUN_60095778(*param_1,0x11,&local_b0);
          *param_3 = 10;
          iVar4 = *(int *)(param_1 + 0xe) + 1;
        }
        *(int *)(param_1 + 0xe) = iVar4;
        uVar9 = *(uint *)(param_1 + 0xe);
        uVar3 = (**(code **)*piVar8)(piVar8);
        if (uVar3 <= uVar9) {
          *(undefined4 *)(param_1 + 0xe) = 0xffff;
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        }
      }
      else {
        FUN_6009582c(*param_1,2);
        *param_3 = 0xc;
        activation_sequence__60068f04(param_1);
      }
    }
  }
  return;
}


