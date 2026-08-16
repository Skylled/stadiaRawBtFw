// 6004703c  FUN_6004703c  size=240 bytes
// --- callers ---
// --- callees ---
//   60047aa8 tasks__60047aa8
//   6004c084 thunk_FUN_601016a2
//   60047f50 FUN_60047f50
//   60047958 FUN_60047958
//   60048580 FUN_60048580
//   600485c8 FUN_600485c8
//   60047ce4 tasks__60047ce4


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_6004703c(uint *param_1,uint param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == (uint *)0x0) {
    thunk_FUN_601016a2(_DAT_60047130,0x131,_DAT_6004712c,param_4,param_4);
  }
  if ((param_2 & 0xff000000) == 0) {
    if (param_2 == 0) {
      uVar2 = 0x133;
      goto LAB_60047064;
    }
  }
  else {
    uVar2 = 0x132;
LAB_60047064:
    thunk_FUN_601016a2(_DAT_60047130,uVar2,_DAT_6004712c);
  }
  iVar1 = FUN_60047f50();
  if ((iVar1 == 0) && (param_5 != 0)) {
    thunk_FUN_601016a2(_DAT_60047130,0x136,_DAT_6004712c);
  }
  FUN_60047958();
  uVar4 = *param_1;
  if (param_4 == 0) {
    if ((param_2 & uVar4) == 0) goto LAB_60047090;
LAB_600470c6:
    if (param_3 == 0) {
      param_5 = 0;
    }
    else {
      param_5 = 0;
      *param_1 = uVar4 & ~param_2;
    }
  }
  else {
    if (param_2 == (param_2 & uVar4)) goto LAB_600470c6;
LAB_60047090:
    if (param_5 != 0) {
      if (param_3 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0x1000000;
      }
      if (param_4 != 0) {
        uVar3 = uVar3 | 0x4000000;
      }
      uVar4 = 0;
      tasks__60047ce4(param_1 + 1,uVar3 | param_2,param_5);
    }
  }
  iVar1 = tasks__60047aa8();
  if (param_5 == 0) {
    return uVar4;
  }
  if (iVar1 == 0) {
    *_DAT_60047134 = 0x10000000;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  uVar4 = func_0x6004c05c();
  if ((int)(uVar4 << 6) < 0) goto LAB_6004710c;
  FUN_60048580();
  uVar4 = *param_1;
  if (param_4 == 0) {
    if ((param_2 & uVar4) != 0) {
LAB_6004711e:
      if (param_3 != 0) {
        *param_1 = uVar4 & ~param_2;
      }
    }
  }
  else if (param_2 == (param_2 & uVar4)) goto LAB_6004711e;
  FUN_600485c8();
LAB_6004710c:
  return uVar4 & 0xffffff;
}


