// 600c5ff4  FUN_600c5ff4  size=174 bytes
// --- callers ---
// --- callees ---
//   600c5fa4 FUN_600c5fa4
//   6013d168 thunk_EXT_FUN_0000b554
//   600c5d3c FUN_600c5d3c
//   600c5db0 FUN_600c5db0


void FUN_600c5ff4(undefined1 param_1,char *param_2)

{
  int iVar1;
  
  switch(param_1) {
  case 0:
    if (*param_2 == '\0') {
      *(char *)(DAT_600c60c4 + 0x141) = param_2[1];
    }
    else {
      *(undefined1 *)(DAT_600c60c4 + 0x141) = 0;
    }
    break;
  default:
    break;
  case 2:
    FUN_600c5fa4(param_2);
    break;
  case 5:
    if ((*(short *)(DAT_600c60c4 + 0x18) != 0) &&
       (iVar1 = thunk_EXT_FUN_0000b554(param_2 + 5,DAT_600c60c8,6), iVar1 == 0)) {
      FUN_600c5db0(0xffff,0x85);
    }
    break;
  case 6:
    if (*(short *)(DAT_600c60c4 + 0x18) != 0) {
      FUN_600c5db0(*(undefined2 *)(param_2 + 2),*param_2);
    }
    break;
  case 7:
    FUN_600c5d3c(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                 *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10),
                 *(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18));
  }
  return;
}


