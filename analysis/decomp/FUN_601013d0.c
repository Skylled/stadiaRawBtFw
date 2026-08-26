// 601013d0  FUN_601013d0  size=204 bytes
// --- callers ---
//   6010149c FUN_6010149c
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   6010135a FUN_6010135a
//   60051088 FUN_60051088
//   600cbbc0 FUN_600cbbc0
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   60101302 FUN_60101302
//   6010152a FUN_6010152a
//   60101a54 FUN_60101a54
//   600cbc18 FUN_600cbc18


uint FUN_601013d0(int *param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_3c [32];
  
  param_2 = param_2 & 0xff;
  if (param_2 == 0) {
    puVar1 = (undefined4 *)FUN_60051088(param_1[2]);
    if (puVar1 == (undefined4 *)0x0) {
      param_2 = 5;
    }
  }
  else {
    puVar1 = (undefined4 *)0x0;
  }
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar4 = param_1[2];
    thunk_EXT_FUN_0000b4c2(iVar2);
    FUN_600cbc18(iVar2 + 100,iVar4,param_2);
    FUN_60101302(iVar2,iVar2 + 100,*(int *)(iVar2 + 0x26c) + 4,0x32);
    thunk_EXT_FUN_00007d10(iVar2);
  }
  if (param_2 == 0) {
    piVar3 = param_1 + 0x45;
    FUN_60101a54(piVar3);
    FUN_6010135a(auStack_3c,puVar1,param_1[2],param_1[4],piVar3,*param_1);
    param_2 = (*(code *)puVar1[3])(auStack_3c,puVar1[4]);
    FUN_6010152a(param_1 + 1);
    iVar2 = *param_1;
    if (iVar2 != 0) {
      uVar5 = *puVar1;
      thunk_EXT_FUN_0000b4c2(iVar2);
      FUN_600cbbc0(iVar2 + 100,uVar5,param_2,0,piVar3);
      FUN_60101302(iVar2,iVar2 + 100,*(int *)(iVar2 + 0x26c) + 4,0x32);
      thunk_EXT_FUN_00007d10(iVar2);
    }
  }
  else {
    FUN_6010152a(param_1 + 1);
  }
  return param_2;
}


