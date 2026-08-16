// 60094a3c  FUN_60094a3c  size=338 bytes
// --- callers ---
// --- callees ---
//   600ee678 FUN_600ee678
//   600eed1a FUN_600eed1a
//   600ef44c FUN_600ef44c
//   600eec5a FUN_600eec5a
//   600eebd8 FUN_600eebd8
//   6009506c FUN_6009506c


void FUN_60094a3c(undefined2 param_1,undefined1 param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_6009506c(param_1);
  iVar3 = FUN_600ef44c(param_1);
  if (((iVar3 != 0) && (iVar2 != 0)) && (*(char *)(iVar2 + 0x1c) == '\x03')) {
    switch(param_2) {
    case 1:
      FUN_600eec5a(iVar3,*(undefined2 *)(param_3 + 5),*(undefined2 *)((int)param_3 + 0x16),*param_3,
                   param_3[1],param_3[2],param_3[3],param_3[4],1);
      break;
    case 2:
      FUN_600eec5a(iVar3,*(undefined2 *)(param_3 + 5),*(undefined2 *)((int)param_3 + 0x16),*param_3,
                   param_3[1],param_3[2],param_3[3],param_3[4],1);
      break;
    case 3:
      cVar1 = FUN_600eebd8(iVar3,*(undefined2 *)((int)param_3 + 0x16),*(undefined2 *)(param_3 + 6),
                           *param_3,param_3[1],param_3[2],param_3[3],param_3[4]);
      if (cVar1 == '\0') {
        FUN_600eec5a(iVar3,*(undefined2 *)((int)param_3 + 0x16),*(undefined2 *)(param_3 + 6),
                     *param_3,param_3[1],param_3[2],param_3[3],param_3[4],0);
      }
      FUN_600ee678(iVar3,*(undefined2 *)(param_3 + 5),param_3,cVar1,0);
      break;
    case 4:
      FUN_600eed1a(iVar3,*(undefined2 *)(param_3 + 1),*(undefined2 *)((int)param_3 + 2),param_3[2],
                   param_3[3],param_3[4],param_3[5],param_3[6],*(undefined1 *)param_3);
      break;
    case 5:
      FUN_600ee678(iVar3,*(undefined2 *)(param_3 + 5),param_3,0,2);
    }
  }
  return;
}


