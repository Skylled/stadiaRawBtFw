// 60061684  partition_table__60061684  size=260 bytes
// src: partition_table.h
// --- callers ---
//   60078340 firmware_image_upload__60078340
//   60061794 FUN_60061794
//   60083f98 FUN_60083f98
// --- callees ---
//   600d4752 FUN_600d4752
//   6010165c FUN_6010165c
//   60101b76 FUN_60101b76
//   60101740 FUN_60101740


/* src: partition_table.h */

undefined4 partition_table__60061684(int *param_1,uint *param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_b0;
  undefined4 local_ac;
  byte *local_a8;
  undefined4 local_a4;
  uint uStack_a0;
  byte local_9c;
  byte local_9b;
  byte local_9a [134];
  
  bVar1 = *param_3;
  uVar5 = (uint)bVar1;
  if (uVar5 == 0) {
    local_b0 = DAT_60061788;
    local_ac = 0x56;
    local_a8 = local_9a;
    local_a4 = 0x80;
    uStack_a0 = uVar5;
    local_9c = bVar1;
    local_9b = bVar1;
    local_9a[0] = bVar1;
    FUN_60101b76(&local_a8,DAT_6006178c);
    FUN_60101740(&local_b0);
  }
  iVar4 = 0;
  do {
    if (param_1[1] == iVar4) {
LAB_600616da:
      FUN_6010165c(0x1e,DAT_60061788,0x82,DAT_60061790,*param_3);
      return 0;
    }
    piVar3 = *(int **)(*param_1 + iVar4 * 4);
    if (*(byte *)(*piVar3 + 8) == uVar5) {
      piVar3 = (int *)piVar3[1];
      if (piVar3 != (int *)0x0) {
        iVar4 = (**(code **)(*piVar3 + 0x14))(piVar3);
        iVar6 = *(int *)(piVar3[1] + 4);
        uVar5 = FUN_600d4752(piVar3,0);
        if (uVar5 == 0) {
          local_9c = 0;
          local_b0 = DAT_60061788;
          local_9b = 0;
          local_ac = 0x8c;
          local_a8 = local_9a;
          local_9a[0] = 0;
          local_a4 = 0x80;
          uStack_a0 = uVar5;
          FUN_60101b76(&local_a8,DAT_6006178c);
          FUN_60101740(&local_b0);
        }
        uVar2 = FUN_600d4752(piVar3,iVar4 * iVar6 + -1);
        if (uVar2 == 0) {
          local_9c = 0;
          local_b0 = DAT_60061788;
          local_9b = 0;
          local_ac = 0x90;
          local_a8 = local_9a;
          local_9a[0] = 0;
          local_a4 = 0x80;
          uStack_a0 = uVar2;
          FUN_60101b76(&local_a8,DAT_6006178c);
          FUN_60101740(&local_b0);
        }
        if (*param_2 < uVar5) {
          return 0;
        }
        if (uVar2 < *param_2) {
          return 0;
        }
        return 1;
      }
      goto LAB_600616da;
    }
    iVar4 = iVar4 + 1;
  } while( true );
}


