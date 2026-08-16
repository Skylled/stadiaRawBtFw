// 600a3014  FUN_600a3014  size=210 bytes
// --- callers ---
//   600f1800 FUN_600f1800
//   600f1e84 FUN_600f1e84
// --- callees ---
//   600aa340 FUN_600aa340
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a01a0 FUN_600a01a0
//   600b27e8 FUN_600b27e8


undefined4
FUN_600a3014(undefined4 param_1,ushort *param_2,char param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  char local_9;
  
  puVar1 = DAT_600a30e8;
  iVar3 = FUN_600a01a0();
  if (iVar3 == 0) {
    uVar4 = 6;
  }
  else if (param_3 == '\x02') {
    cVar2 = FUN_600b27e8(param_1,1,0,0);
    if (cVar2 == '\0') {
      uVar4 = 3;
    }
    else {
      uVar4 = 1;
    }
  }
  else if (param_3 == '\x01') {
    if (*(char *)((int)puVar1 + 0x32) == '\0') {
      *puVar1 = param_5;
      thunk_EXT_FUN_0000b572(puVar1 + 0xb,param_1,6);
      FUN_600aa340(puVar1 + 1,8,param_4);
      if (param_2 == (ushort *)0x0) {
        local_9 = FUN_600b27e8(param_1,1,0,0);
      }
      else {
        local_9 = FUN_600b27e8(param_1,*(undefined1 *)((int)param_2 + 0xb),
                               *(undefined1 *)((int)param_2 + 0xd),
                               DAT_600a30ec & 0xffff | (uint)*param_2);
      }
      if (local_9 == '\0') {
        uVar4 = 3;
      }
      else {
        *(undefined1 *)((int)puVar1 + 0x32) = 1;
        uVar4 = 1;
      }
    }
    else {
      uVar4 = 2;
    }
  }
  else {
    uVar4 = 5;
  }
  return uVar4;
}


