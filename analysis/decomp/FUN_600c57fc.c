// 600c57fc  FUN_600c57fc  size=194 bytes
// --- callers ---
// --- callees ---
//   600ff718 FUN_600ff718
//   600ff862 FUN_600ff862
//   600ff672 FUN_600ff672
//   600ff79e FUN_600ff79e
//   600c6fe4 FUN_600c6fe4
//   600ff694 FUN_600ff694
//   600ff6d0 FUN_600ff6d0
//   600ff800 FUN_600ff800
//   600ff764 FUN_600ff764


void FUN_600c57fc(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  if ((param_1 != 0) && ((iVar2 = param_1 + 0xc, iVar2 != 0 || (*(char *)(param_1 + 8) == '\b')))) {
    uVar1 = *(undefined1 *)(param_1 + 9);
    switch(*(undefined1 *)(param_1 + 8)) {
    case 0:
      FUN_600c6fe4(iVar2);
      break;
    case 1:
      FUN_600ff672(iVar2);
      break;
    case 2:
      FUN_600ff694(uVar1,iVar2);
      break;
    case 3:
      FUN_600ff6d0(uVar1,iVar2);
      break;
    case 4:
      FUN_600ff718(uVar1,iVar2);
      break;
    case 5:
      FUN_600ff764(uVar1,iVar2);
      break;
    case 6:
      FUN_600ff79e(uVar1,iVar2);
      break;
    case 7:
      FUN_600ff800(uVar1,iVar2);
      break;
    case 8:
      FUN_600ff862(uVar1);
    }
  }
  return;
}


