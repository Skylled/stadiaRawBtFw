// 600cb2fc  key_value_store__600cb2fc  size=148 bytes
// src: key_value_store.cc
// --- callers ---
//   60101198 FUN_60101198
//   600cb6fc key_value_store__600cb6fc
// --- callees ---
//   60101b76 FUN_60101b76
//   600cbb14 FUN_600cbb14
//   6010165c FUN_6010165c


/* src: key_value_store.cc */

undefined1
key_value_store__600cb2fc
          (int param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,undefined1 param_5)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char local_2c [4];
  int local_28 [3];
  char local_1c;
  undefined1 local_1b;
  
  if (*(byte *)(param_1 + 0xab8) < 100) {
    iVar2 = (short)(ushort)*(byte *)(param_1 + 0xab8) * 0x18 + 0x158;
    local_1c = '\0';
    local_28[0] = param_1 + iVar2;
    *(undefined1 *)(param_1 + iVar2) = 0;
    local_1b = 0;
    local_28[1] = 0x10;
    local_28[2] = 0;
    FUN_60101b76(local_28);
    if (local_1c == '\0') {
      bVar1 = *(byte *)(param_1 + 0xab8);
      iVar2 = (uint)bVar1 * 0x18 + param_1;
      *(undefined4 *)(iVar2 + 0x168) = param_3;
      *(undefined2 *)(iVar2 + 0x16c) = param_4;
      *(undefined1 *)(iVar2 + 0x16e) = param_5;
      *(byte *)(param_1 + 0xab8) = bVar1 + 1;
      return 0;
    }
    local_2c[0] = local_1c;
    uVar5 = FUN_600cbb14(local_2c);
    uVar3 = 0x2d6;
    uVar4 = DAT_600cb398;
  }
  else {
    uVar3 = 0x2cc;
    uVar5 = 100;
    uVar4 = DAT_600cb390;
  }
  FUN_6010165c(0x28,DAT_600cb394,uVar3,uVar4,uVar5);
  return 0xd;
}


