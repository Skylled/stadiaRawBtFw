// 60042050  FUN_60042050  size=206 bytes
// --- callers ---
// --- callees ---
//   60047290 queue__60047290
//   600473e4 queue__600473e4


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_60042050(int param_1,int param_2,uint param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  int iStack_b0;
  uint uStack_ac;
  int iStack_a8;
  undefined4 uStack_a4;
  undefined1 auStack_a0 [144];
  
  iStack_b0 = param_2;
  uStack_ac = param_3;
  if (param_2 == *(int *)(param_1 + 100)) {
    switch(param_2) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
      uVar2 = *(uint *)(param_1 + 0x68);
      break;
    case 7:
      param_3 = param_3 & 0xff;
      uVar2 = (uint)*(byte *)(param_1 + 0x68);
      break;
    case 10:
      goto code_r0x60042088;
    default:
      goto LAB_6004209c;
    }
    if (param_3 == uVar2) {
code_r0x60042088:
      if ((*(uint *)(iRam6004215c + 4) & 0x1ff) == 0) {
        iVar1 = queue__600477e4(*(undefined4 *)(param_1 + 0xbc));
      }
      else {
        iVar1 = func_0x6004c294();
      }
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
LAB_6004209c:
  if (param_4 == 1) {
    iStack_a8 = 0;
    iVar1 = queue__600473e4(*(undefined4 *)(param_1 + 0xbc),&iStack_b0,&iStack_a8);
    bVar3 = iVar1 == 1;
    if (iStack_a8 != 0) {
      *_DAT_60042160 = 0x10000000;
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
    }
  }
  else {
    if (param_4 != 2) {
      if (param_4 == 0) {
        queue__60047290(*(undefined4 *)(param_1 + 0xbc),&iStack_b0,0xffffffff,0);
      }
      goto LAB_600420b6;
    }
    iVar1 = queue__60047290(*(undefined4 *)(param_1 + 0xbc),&iStack_b0,param_5,0);
    bVar3 = iVar1 == 1;
  }
  if (!bVar3) {
    iStack_a8 = _DAT_60042164;
    uStack_a4 = 0x2de;
    func_0x6004be84(auStack_a0);
    func_0x6004c444(auStack_a0,_DAT_60042168);
    func_0x6004bf04(auStack_a0,&iStack_b0);
    func_0x6004c444(auStack_a0,_DAT_6004216c);
    func_0x6004bf04(auStack_a0,param_1 + 0x560);
    func_0x6004c41c(0x1e,iStack_a8,uStack_a4,auStack_a0);
    return 0;
  }
LAB_600420b6:
  *(int *)(param_1 + 100) = iStack_b0;
  *(uint *)(param_1 + 0x68) = uStack_ac;
  return 1;
}


