// 600661fc  keys__600661fc  size=116 bytes
// src: keys.cc
// --- callers ---
//   60066d94 keys__60066d94
// --- callees ---
//   600d37b8 FUN_600d37b8
//   600d37ac FUN_600d37ac
//   60065ccc FUN_60065ccc
//   60065db0 FUN_60065db0
//   60051120 FUN_60051120
//   6010112c FUN_6010112c


/* src: keys.cc */

uint keys__600661fc(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStack_ac [8];
  undefined1 auStack_a4 [144];
  byte local_14;
  
  iVar1 = FUN_60065ccc();
  if (iVar1 == DAT_60066270) {
    FUN_60051120(auStack_ac,DAT_60066274,0x324,3);
    uVar2 = DAT_60066278;
  }
  else {
    if (*(char *)(iVar1 + 0xe) != '\x01') {
      uVar2 = FUN_60065db0(param_1);
      uVar3 = FUN_6010112c(uVar2,*(undefined4 *)(iVar1 + 8));
      return uVar3;
    }
    FUN_60051120(auStack_ac,DAT_60066274,0x326,7);
    FUN_600d37ac(auStack_a4,DAT_6006627c);
    FUN_600d37ac(auStack_a4,*(undefined4 *)(iVar1 + 8));
    uVar2 = DAT_60066280;
  }
  FUN_600d37ac(auStack_a4,uVar2);
  FUN_600d37b8(auStack_ac);
  return (uint)local_14;
}


