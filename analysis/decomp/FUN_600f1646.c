// 600f1646  FUN_600f1646  size=104 bytes
// --- callers ---
// --- callees ---
//   6009f1fc FUN_6009f1fc
//   600f15b0 FUN_600f15b0
//   6009f27c FUN_6009f27c
//   6009f124 FUN_6009f124


void FUN_600f1646(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  uVar2 = *(undefined2 *)(param_1 + 2);
  cVar1 = *(char *)(iVar3 + 1);
  if (cVar1 == '\x04') {
    FUN_6009f124(iVar3,uVar2);
  }
  else if (cVar1 == '\x02') {
    FUN_6009f1fc(iVar3,uVar2);
  }
  else if (cVar1 == '\x03') {
    FUN_6009f27c(iVar3,uVar2);
  }
  else if (cVar1 == '\r') {
    FUN_600f15b0(iVar3,uVar2);
  }
  return;
}


