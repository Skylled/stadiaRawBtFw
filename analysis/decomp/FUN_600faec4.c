// 600faec4  FUN_600faec4  size=488 bytes
// --- callers ---
// --- callees ---
//   600fcbfa FUN_600fcbfa
//   600c2304 FUN_600c2304
//   600f2080 FUN_600f2080
//   600c1a34 FUN_600c1a34
//   6009ff18 FUN_6009ff18
//   600fab3e FUN_600fab3e
//   600bffe8 FUN_600bffe8


void FUN_600faec4(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 local_11;
  int local_10;
  undefined1 *local_c;
  
  local_11 = 6;
  local_c = param_2;
  local_10 = FUN_6009ff18(param_1 + 0x1d);
  if ((local_10 != 0) && (*(char *)(param_1 + 0x26) == '\x01')) {
    FUN_600f2080(local_10);
  }
  *(ushort *)(param_1 + 0x28) = *(ushort *)(param_1 + 0x28) | 0x10;
  *(undefined1 *)(param_1 + 0x18d) = *local_c;
  *(undefined1 *)(param_1 + 399) = local_c[1];
  *(undefined1 *)(param_1 + 0x191) = local_c[2];
  *(undefined1 *)(param_1 + 0x1b0) = local_c[3];
  *(undefined1 *)(param_1 + 0x1b2) = local_c[4];
  *(undefined1 *)(param_1 + 0x1b3) = local_c[5];
  local_c = local_c + 6;
  iVar2 = FUN_600c2304(param_1);
  if (iVar2 == 0) {
    if (((*(byte *)(param_1 + 0x191) & 0x10) != 0) && ((*(byte *)(param_1 + 0x191) & 8) == 0)) {
      *(byte *)(param_1 + 0x191) = *(byte *)(param_1 + 0x191) & 0xef;
    }
    if ((*(char *)(param_1 + 0x193) != '\0') && ((*(byte *)(param_1 + 0x191) & 8) == 0)) {
      local_11 = 3;
      FUN_600c1a34(param_1,0x17,&local_11);
    }
    if (*(char *)(param_1 + 0x26) == '\x01') {
      if ((*(ushort *)(param_1 + 0x28) & 1) == 0) {
        *(undefined1 *)(param_1 + 0x1b4) = *(undefined1 *)(param_1 + 0x1b2);
        *(undefined1 *)(param_1 + 0x1b5) = *(undefined1 *)(param_1 + 0x1b3);
        *(undefined1 *)(param_1 + 0x2a) = 2;
      }
      else {
        *(byte *)(param_1 + 0x1b4) = *(byte *)(param_1 + 0x1b2) & *(byte *)(param_1 + 0x1b4);
        *(byte *)(param_1 + 0x1b5) = *(byte *)(param_1 + 0x1b3) & *(byte *)(param_1 + 0x1b5);
        uVar1 = FUN_600fcbfa(param_1);
        *(undefined1 *)(param_1 + 0x194) = uVar1;
        FUN_600fab3e(param_1,0);
      }
    }
    else {
      uVar1 = FUN_600fcbfa(param_1);
      *(undefined1 *)(param_1 + 0x194) = uVar1;
      if ((*(char *)(param_1 + 0x193) == '\0') ||
         ((*(char *)(param_1 + 0x195) != '\0' && (*(char *)(param_1 + 0x194) != '\x04')))) {
        FUN_600bffe8(param_1,0);
      }
      else {
        local_11 = 3;
        FUN_600c1a34(param_1,0x17,&local_11);
      }
    }
  }
  else {
    local_11 = 10;
    FUN_600c1a34(param_1,0x17,&local_11);
  }
  return;
}


