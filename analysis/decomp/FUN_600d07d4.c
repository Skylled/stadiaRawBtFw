// 600d07d4  FUN_600d07d4  size=192 bytes
// --- callers ---
// --- callees ---
//   600d0bc8 FUN_600d0bc8
//   600d1178 FUN_600d1178


undefined4 FUN_600d07d4(undefined4 *param_1,int param_2,int *param_3,uint *param_4)

{
  ushort uVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined4 uStack_28;
  int local_24;
  int *local_20;
  undefined4 local_1c;
  
  uVar1 = *(ushort *)(param_2 + 2);
  uStack_28 = param_1;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  FUN_600d1178(*param_1,6,(int)&uStack_28 + 3);
  if (2 < uStack_28._3_1_) {
    return 5;
  }
  local_20 = (int *)(uint)*(ushort *)(param_2 + 6);
  if (uVar1 >> 8 == 1) {
    uVar4 = 0xb;
  }
  else {
    cVar2 = (char)(uVar1 >> 8);
    uVar3 = (undefined1)uVar1;
    if (uVar1 >> 8 == 2) {
      local_1c = (uint *)CONCAT31(local_1c._1_3_,uVar3);
      uVar4 = 0xc;
    }
    else if (cVar2 == '\x03') {
      uVar4 = 0xd;
      local_1c = (uint *)CONCAT22(CONCAT11(local_1c._3_1_,uVar3),*(undefined2 *)(param_2 + 4));
    }
    else if (cVar2 == '!') {
      uVar4 = 0xe;
      local_1c = (uint *)CONCAT31(local_1c._1_3_,(char)*(undefined2 *)(param_2 + 4));
    }
    else if (cVar2 == '\"') {
      uVar4 = 0xf;
      local_1c = (uint *)CONCAT31(local_1c._1_3_,(char)*(undefined2 *)(param_2 + 4));
    }
    else if (cVar2 == '#') {
      uVar4 = 0x10;
      local_1c._0_2_ = CONCAT11((char)*(undefined2 *)(param_2 + 4),uVar3);
    }
    else if (cVar2 == '\x06') {
      uVar4 = 0x12;
    }
    else {
      if (cVar2 != '\x0f') {
        uVar4 = 5;
        goto LAB_600d080a;
      }
      local_1c = (uint *)CONCAT31(local_1c._1_3_,uVar3);
      uVar4 = 0x11;
    }
  }
  uVar4 = FUN_600d0bc8(*param_1,uVar4,&local_24);
LAB_600d080a:
  *param_3 = local_24;
  *param_4 = (uint)local_20;
  return uVar4;
}


