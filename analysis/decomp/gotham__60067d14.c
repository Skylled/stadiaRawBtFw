// 60067d14  gotham__60067d14  size=156 bytes
// src: gotham.cc
// --- callers ---
//   600dfbac FUN_600dfbac
//   600781d4 FUN_600781d4
//   6005a4cc device_info__6005a4cc
// --- callees ---
//   600e02f4 FUN_600e02f4
//   600d37b8 FUN_600d37b8
//   60084bec bio__60084bec
//   600e02fc FUN_600e02fc
//   600e02f8 FUN_600e02f8
//   600e0242 FUN_600e0242
//   6010165c FUN_6010165c
//   60101b76 FUN_60101b76
//   600d3ae6 FUN_600d3ae6


/* src: gotham.cc */

int * gotham__60067d14(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [134];
  
  if (*DAT_60067db0 == 0) {
    uVar4 = 0xae;
    iVar1 = 0;
    uVar5 = DAT_60067db4;
  }
  else {
    iVar1 = bio__60084bec(*DAT_60067db0);
    if (iVar1 != 0) {
      *(int *)(*param_2 + 4) = iVar1;
      *param_2 = 0;
      FUN_600e02f4();
      piVar2 = (int *)FUN_600e02f8(iVar1);
      uVar3 = (**(code **)(*piVar2 + 8))();
      if ((uVar3 & 0xff) != 0) {
        local_b0 = DAT_60067db8;
        local_9c = 0;
        local_ac = 0xbd;
        local_a8 = local_9a;
        local_9b = 0;
        local_9a[0] = 0;
        local_a4 = 0x80;
        uStack_a0 = 0;
        FUN_60101b76(&local_a8,DAT_60067dc0);
        FUN_600d3ae6(&local_a8,uVar3);
        FUN_600d37b8(&local_b0);
        *param_1 = 0;
        FUN_600e0242(iVar1);
        return param_1;
      }
      FUN_600e02fc(iVar1,1);
      goto LAB_60067d2e;
    }
    uVar4 = 0xb4;
    uVar5 = DAT_60067dbc;
  }
  FUN_6010165c(0x28,DAT_60067db8,uVar4,uVar5);
LAB_60067d2e:
  *param_1 = iVar1;
  return param_1;
}


