// 60094c5c  FUN_60094c5c  size=196 bytes
// --- callers ---
//   600fea16 FUN_600fea16
// --- callees ---
//   60094754 FUN_60094754
//   600ee678 FUN_600ee678
//   600d9250 FUN_600d9250
//   6006ddd8 FUN_6006ddd8
//   600ee57a FUN_600ee57a


void FUN_60094c5c(int param_1,short param_2,int param_3,short param_4)

{
  undefined4 uVar1;
  int iVar2;
  int local_1c;
  short local_16;
  
  local_1c = param_3;
  local_16 = param_2;
  if (param_4 == 0) {
    while (*(int *)(param_1 + 0x14) != 0) {
      uVar1 = FUN_600d9250(param_1 + 0x14);
      FUN_6006ddd8(uVar1,DAT_60094d20,0x5da);
    }
    iVar2 = FUN_60094754(param_1);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0xc);
    }
  }
  for (; (local_16 != 0 && (local_1c != 0)); local_1c = local_1c + 0x1c) {
    if (*(byte *)(local_1c + 0x18) < 3) {
      FUN_600ee678(param_1,*(undefined2 *)(local_1c + 0x14),local_1c,
                   *(undefined1 *)(local_1c + 0x1a),*(undefined1 *)(local_1c + 0x18));
    }
    else if (*(byte *)(local_1c + 0x18) == 3) {
      FUN_600ee57a(param_1,*(undefined2 *)(local_1c + 0x14),*(undefined2 *)(local_1c + 0x16),
                   local_1c,*(undefined1 *)(local_1c + 0x1b),*(undefined1 *)(local_1c + 0x19));
    }
    local_16 = local_16 + -1;
  }
  return;
}


