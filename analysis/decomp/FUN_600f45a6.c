// 600f45a6  FUN_600f45a6  size=270 bytes
// --- callers ---
//   600ac014 FUN_600ac014
//   600f4266 FUN_600f4266
// --- callees ---
//   600f47a0 FUN_600f47a0
//   600b00b4 FUN_600b00b4
//   600f70b4 FUN_600f70b4


void FUN_600f45a6(int *param_1,char param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  char local_11;
  
  iVar3 = *param_1;
  local_11 = '\0';
  iVar4 = param_1[3];
  if (iVar4 == 0) {
    local_11 = -0x7f;
  }
  else {
    cVar1 = *(char *)((int)param_1 + 0x32);
    if (cVar1 == '\x02') {
      if ((int)(*(ushort *)(iVar3 + 0x1a) - 3) < (int)(uint)*(ushort *)(iVar4 + 6)) {
        FUN_600f47a0(iVar3,param_1);
      }
      else {
        *(undefined2 *)(param_1 + 10) = *(undefined2 *)(iVar4 + 2);
        local_11 = FUN_600f70b4(iVar3,*(undefined2 *)((int)param_1 + 0x26),0x12,
                                *(undefined2 *)(iVar4 + 2),*(undefined2 *)(iVar4 + 6),0,iVar4 + 9);
      }
    }
    else if (cVar1 == '\x03') {
      FUN_600f47a0(iVar3,param_1);
    }
    else if (cVar1 == '\x01') {
      *(undefined2 *)(param_1 + 10) = *(undefined2 *)(iVar4 + 2);
      if (param_2 == '\x02') {
        uVar2 = 0xd2;
      }
      else {
        uVar2 = 0x52;
      }
      local_11 = FUN_600f70b4(iVar3,*(undefined2 *)((int)param_1 + 0x26),uVar2,
                              *(undefined2 *)(iVar4 + 2),*(undefined2 *)(iVar4 + 6),0,iVar4 + 9);
    }
    else {
      local_11 = -0x7f;
    }
  }
  if ((((local_11 != '\0') && (local_11 != -0x7a)) && (local_11 != -0x71)) ||
     ((local_11 != -0x7a && (*(char *)((int)param_1 + 0x32) == '\x01')))) {
    FUN_600b00b4(param_1,local_11,0);
  }
  return;
}


