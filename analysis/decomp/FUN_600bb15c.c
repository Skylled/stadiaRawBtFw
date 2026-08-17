// 600bb15c  FUN_600bb15c  size=146 bytes
// --- callers ---
//   600bb2ac FUN_600bb2ac
//   600b89b8 FUN_600b89b8
// --- callees ---
//   600d9290 FUN_600d9290
//   600b9e28 FUN_600b9e28
//   600aa3cc FUN_600aa3cc
//   600aa340 FUN_600aa340
//   600d92f8 FUN_600d92f8
//   600d92fc FUN_600d92fc


void FUN_600bb15c(char param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  
  iVar1 = DAT_600bb1f0;
  if (*(short *)(DAT_600bb1f0 + 8) != 0) {
    if (param_1 == '\0') {
      FUN_600aa3cc(DAT_600bb1f4);
    }
    iVar2 = FUN_600d92f8(iVar1);
    while (local_c = iVar2, local_c != 0) {
      iVar2 = FUN_600d92fc(local_c);
      if (((param_1 == '\0') || (*(short *)(local_c + 6) == 0)) ||
         (*(short *)(local_c + 6) = *(short *)(local_c + 6) + -1, *(short *)(local_c + 6) == 0)) {
        FUN_600d9290(iVar1,local_c);
        *(undefined2 *)(local_c + 6) = 0xffff;
        FUN_600b9e28(local_c);
      }
    }
    if (*(short *)(iVar1 + 8) != 0) {
      FUN_600aa340(DAT_600bb1f4,4,2);
    }
  }
  return;
}


