// 60067a68  gotham__60067a68  size=216 bytes
// src: gotham.cc
// --- callers ---
// --- callees ---
//   60084c90 bio__60084c90
//   600d37b8 FUN_600d37b8
//   600e02f8 FUN_600e02f8
//   600e02a8 FUN_600e02a8
//   6010165c FUN_6010165c
//   60101b76 FUN_60101b76
//   600d3ae6 FUN_600d3ae6


/* src: gotham.cc */

undefined4 gotham__60067a68(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined1 *local_b0;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined1 local_a4;
  undefined1 local_a3;
  undefined1 local_a2 [134];
  
  piVar1 = (int *)FUN_600e02f8();
  if (piVar1 == (int *)0x0) {
    FUN_6010165c(0x28,DAT_60067b44,0x5a,DAT_60067b40);
    return 0;
  }
  iVar2 = FUN_600e02a8(param_1);
  if (param_2 == 0xb) {
    uVar3 = (**(code **)(*piVar1 + 0x14))(piVar1);
    if ((uVar3 & 0xff) != 0) {
      local_b4 = 0x62;
      uVar4 = DAT_60067b48;
LAB_60067ad2:
      local_b0 = local_a2;
      local_a2[0] = 0;
      local_a3 = 0;
      local_a4 = 0;
      uStack_a8 = 0;
      local_ac = 0x80;
      local_b8 = DAT_60067b44;
      FUN_60101b76(&local_b0,uVar4);
      FUN_600d3ae6(&local_b0,uVar3);
      FUN_600d37b8(&local_b8);
      return 0;
    }
    if (iVar2 == 0) {
      return 1;
    }
  }
  else if (param_2 == 1) {
    uVar3 = (**(code **)(*piVar1 + 0x18))(piVar1);
    if ((uVar3 & 0xff) != 0) {
      local_b4 = 0x6c;
      uVar4 = DAT_60067b4c;
      goto LAB_60067ad2;
    }
    if (iVar2 == 0) {
      return 1;
    }
  }
  uVar4 = FUN_600e02a8(param_1);
  uVar4 = bio__60084c90(uVar4,param_2,param_3,param_4);
  return uVar4;
}


