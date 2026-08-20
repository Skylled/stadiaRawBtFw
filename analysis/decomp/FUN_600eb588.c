// 600eb588  FUN_600eb588  size=466 bytes
// --- callers ---
// --- callees ---
//   600e652a FUN_600e652a
//   600e643a FUN_600e643a
//   600e65d2 FUN_600e65d2
//   600e69c2 FUN_600e69c2
//   600e653e FUN_600e653e
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e6a90 FUN_600e6a90
//   600eb562 FUN_600eb562
//   600e66be FUN_600e66be
//   600e5664 FUN_600e5664
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600e63a4 FUN_600e63a4


void FUN_600eb588(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  int extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  undefined4 extraout_r2_02;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  undefined1 local_76a;
  undefined1 local_769;
  undefined1 auStack_768 [32];
  undefined1 auStack_748 [32];
  undefined1 auStack_728 [32];
  undefined1 auStack_708 [32];
  undefined1 auStack_6e8 [32];
  undefined1 auStack_6c8 [32];
  undefined1 auStack_6a8 [32];
  undefined1 auStack_688 [32];
  undefined1 auStack_668 [32];
  undefined1 auStack_648 [32];
  undefined1 auStack_628 [32];
  undefined1 auStack_608 [32];
  undefined1 auStack_5e8 [32];
  undefined1 auStack_5c8 [1444];
  
  thunk_EXT_FUN_0000af90(auStack_688,0,0x660);
  FUN_600e643a(auStack_628,param_3);
  uVar9 = 2;
  FUN_600e643a(auStack_608,param_3 + 0x44);
  puVar8 = auStack_5c8;
  FUN_600e643a(auStack_5e8,param_3 + 0x88);
  do {
    if ((int)(uVar9 << 0x1f) < 0) {
      FUN_600e66be(puVar8,puVar8 + 0x20,puVar8 + 0x40,auStack_628,auStack_608,auStack_5e8,0,
                   puVar8 + -0x60,puVar8 + -0x40,puVar8 + -0x20);
    }
    else {
      iVar7 = (uVar9 >> 1) * 0x60;
      FUN_600e65d2(puVar8,puVar8 + 0x20,puVar8 + 0x40,auStack_688 + iVar7,auStack_668 + iVar7,
                   auStack_648 + iVar7);
    }
    uVar9 = uVar9 + 1;
    puVar8 = puVar8 + 0x60;
  } while (uVar9 != 0x11);
  bVar11 = true;
  thunk_EXT_FUN_0000b5ba(auStack_748,0,0x60);
  uVar9 = 0xff;
LAB_600eb61a:
  uVar10 = uVar9 - 1;
  if (uVar9 == (uVar9 / 5) * 5) {
    cVar1 = FUN_600e6a90(param_4,uVar9 + 4);
    cVar2 = FUN_600e6a90(param_4,extraout_r2 + 3);
    cVar3 = FUN_600e6a90(param_4,extraout_r2_00 + 2);
    cVar4 = FUN_600e6a90(param_4,extraout_r2_01 + 1);
    cVar5 = FUN_600e6a90(param_4,extraout_r2_02);
    bVar6 = FUN_600e6a90(param_4,uVar10);
    FUN_600eb562(&local_76a,&local_769,
                 bVar6 | cVar2 << 4 | cVar1 << 5 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1);
    FUN_600e69c2(local_769,0x11,auStack_688,auStack_6e8);
    FUN_600e5664(auStack_768,auStack_6c8);
    FUN_600e653e(auStack_6c8,local_76a,auStack_6c8,auStack_768);
    if (bVar11) {
      FUN_600e652a(auStack_748,auStack_6e8);
      FUN_600e652a(auStack_728,auStack_6c8);
      FUN_600e652a(auStack_708,auStack_6a8);
    }
    else {
      FUN_600e66be(auStack_748,auStack_728,auStack_708,auStack_748,auStack_728,auStack_708,0,
                   auStack_6e8,auStack_6c8,auStack_6a8);
    }
    if (uVar9 != 0) goto LAB_600eb742;
  }
  else if (uVar10 != 0xffffffff) goto code_r0x600eb73c;
  FUN_600e63a4(param_2,auStack_748);
  FUN_600e63a4(param_2 + 0x44,auStack_728);
  FUN_600e63a4(param_2 + 0x88,auStack_708);
  return;
code_r0x600eb73c:
  uVar9 = uVar10;
  if (!bVar11) {
LAB_600eb742:
    bVar11 = false;
    FUN_600e65d2(auStack_748);
    uVar9 = uVar10;
  }
  goto LAB_600eb61a;
}


