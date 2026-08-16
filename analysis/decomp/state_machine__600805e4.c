// 600805e4  state_machine__600805e4  size=110 bytes
// src: state_machine.cc
// --- callers ---
//   6008099c state_machine__6008099c
// --- callees ---
//   6010165c FUN_6010165c
//   600df218 FUN_600df218


/* src: state_machine.cc */

undefined4 state_machine__600805e4(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  switch(*param_2) {
  case 0:
    uVar2 = 1;
    *(undefined1 *)(param_1 + 0xe5) = 1;
    break;
  case 1:
    *(undefined1 *)(param_1 + 0xe5) = 0;
    goto LAB_6008060c;
  case 2:
    *(undefined1 *)(param_1 + 0xe5) = 0;
    uVar2 = 5;
    break;
  case 3:
    iVar1 = FUN_600df218();
    if (iVar1 == 4) {
      return 4;
    }
    goto LAB_6008062e;
  case 4:
    uVar2 = 4;
    break;
  case 5:
    iVar1 = FUN_600df218();
    if (iVar1 != 4) goto LAB_60080618;
LAB_6008062e:
    if (*(char *)(param_1 + 0xe5) == '\0') {
LAB_6008060c:
      uVar2 = 3;
    }
    else {
LAB_60080636:
      uVar2 = 1;
    }
    break;
  case 6:
    iVar1 = FUN_600df218();
    if (iVar1 == 1) {
      return 2;
    }
LAB_60080618:
    uVar2 = 6;
    break;
  case 7:
    uVar2 = 0;
    break;
  default:
    FUN_6010165c(0x28,DAT_60080660,0xfd,DAT_6008065c);
    goto LAB_60080636;
  }
  return uVar2;
}


