; ModuleID = 'virtualFun1.cpp'
source_filename = "virtualFun1.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%class.A = type <{ i32 (...)**, i32, [4 x i8] }>
%class.B = type <{ i32 (...)**, i32, [4 x i8] }>
%class.C = type { %class.A.base, [4 x i8], %class.B.base, i32 }
%class.A.base = type <{ i32 (...)**, i32 }>
%class.B.base = type <{ i32 (...)**, i32 }>

$_ZN1AC1Ev = comdat any

$_ZN1BC1Ev = comdat any

$_ZN1CC1Ev = comdat any

$_ZN1CD1Ev = comdat any

$_ZN1BD1Ev = comdat any

$_ZN1AD1Ev = comdat any

$_ZN1AC2Ev = comdat any

$_ZN1A6setIntEi = comdat any

$_ZN1A6getIntEv = comdat any

$_ZN1BC2Ev = comdat any

$_ZN1B6setIntEi = comdat any

$_ZN1B6getIntEv = comdat any

$_ZN1CC2Ev = comdat any

$_ZN1C6setIntEi = comdat any

$_ZN1C6getIntEv = comdat any

$_ZThn16_N1C6setIntEi = comdat any

$_ZThn16_N1C6getIntEv = comdat any

$_ZN1CD2Ev = comdat any

$_ZN1BD2Ev = comdat any

$_ZN1AD2Ev = comdat any

$_ZTV1A = comdat any

$_ZTS1A = comdat any

$_ZTI1A = comdat any

$_ZTV1B = comdat any

$_ZTS1B = comdat any

$_ZTI1B = comdat any

$_ZTV1C = comdat any

$_ZTS1C = comdat any

$_ZTI1C = comdat any

@_ZTV1A = linkonce_odr unnamed_addr constant { [4 x i8*] } { [4 x i8*] [i8* null, i8* bitcast ({ i8*, i8* }* @_ZTI1A to i8*), i8* bitcast (void (%class.A*, i32)* @_ZN1A6setIntEi to i8*), i8* bitcast (i32 (%class.A*)* @_ZN1A6getIntEv to i8*)] }, comdat, align 8
@_ZTVN10__cxxabiv117__class_type_infoE = external global i8*
@_ZTS1A = linkonce_odr constant [3 x i8] c"1A\00", comdat, align 1
@_ZTI1A = linkonce_odr constant { i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv117__class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_ZTS1A, i32 0, i32 0) }, comdat, align 8
@_ZTV1B = linkonce_odr unnamed_addr constant { [4 x i8*] } { [4 x i8*] [i8* null, i8* bitcast ({ i8*, i8* }* @_ZTI1B to i8*), i8* bitcast (void (%class.B*, i32)* @_ZN1B6setIntEi to i8*), i8* bitcast (i32 (%class.B*)* @_ZN1B6getIntEv to i8*)] }, comdat, align 8
@_ZTS1B = linkonce_odr constant [3 x i8] c"1B\00", comdat, align 1
@_ZTI1B = linkonce_odr constant { i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv117__class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_ZTS1B, i32 0, i32 0) }, comdat, align 8
@_ZTV1C = linkonce_odr unnamed_addr constant { [4 x i8*], [4 x i8*] } { [4 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i32, i32, i8*, i64, i8*, i64 }* @_ZTI1C to i8*), i8* bitcast (void (%class.C*, i32)* @_ZN1C6setIntEi to i8*), i8* bitcast (i32 (%class.C*)* @_ZN1C6getIntEv to i8*)], [4 x i8*] [i8* inttoptr (i64 -16 to i8*), i8* bitcast ({ i8*, i8*, i32, i32, i8*, i64, i8*, i64 }* @_ZTI1C to i8*), i8* bitcast (void (%class.C*, i32)* @_ZThn16_N1C6setIntEi to i8*), i8* bitcast (i32 (%class.C*)* @_ZThn16_N1C6getIntEv to i8*)] }, comdat, align 8
@_ZTVN10__cxxabiv121__vmi_class_type_infoE = external global i8*
@_ZTS1C = linkonce_odr constant [3 x i8] c"1C\00", comdat, align 1
@_ZTI1C = linkonce_odr constant { i8*, i8*, i32, i32, i8*, i64, i8*, i64 } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv121__vmi_class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_ZTS1C, i32 0, i32 0), i32 0, i32 2, i8* bitcast ({ i8*, i8* }* @_ZTI1A to i8*), i64 2, i8* bitcast ({ i8*, i8* }* @_ZTI1B to i8*), i64 4098 }, comdat, align 8

; Function Attrs: noinline norecurse nounwind optnone
define i32 @main(i32 %argc, i8** %argv) #0 {
entry:
  %retval = alloca i32, align 4
  %argc.addr = alloca i32, align 4
  %argv.addr = alloca i8**, align 8
  %a = alloca %class.A, align 8
  %b = alloca %class.B, align 8
  %c = alloca %class.C, align 8
  store i32 0, i32* %retval, align 4
  store i32 %argc, i32* %argc.addr, align 4
  store i8** %argv, i8*** %argv.addr, align 8
  call void @_ZN1AC1Ev(%class.A* %a)
  call void @_ZN1BC1Ev(%class.B* %b)
  call void @_ZN1CC1Ev(%class.C* %c)
  store i32 0, i32* %retval, align 4
  call void @_ZN1CD1Ev(%class.C* %c) #2
  call void @_ZN1BD1Ev(%class.B* %b) #2
  call void @_ZN1AD1Ev(%class.A* %a) #2
  %0 = load i32, i32* %retval, align 4
  ret i32 %0
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1AC1Ev(%class.A* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.A*, align 8
  store %class.A* %this, %class.A** %this.addr, align 8
  %this1 = load %class.A*, %class.A** %this.addr, align 8
  call void @_ZN1AC2Ev(%class.A* %this1)
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1BC1Ev(%class.B* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.B*, align 8
  store %class.B* %this, %class.B** %this.addr, align 8
  %this1 = load %class.B*, %class.B** %this.addr, align 8
  call void @_ZN1BC2Ev(%class.B* %this1)
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1CC1Ev(%class.C* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.C*, align 8
  store %class.C* %this, %class.C** %this.addr, align 8
  %this1 = load %class.C*, %class.C** %this.addr, align 8
  call void @_ZN1CC2Ev(%class.C* %this1)
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1CD1Ev(%class.C* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.C*, align 8
  store %class.C* %this, %class.C** %this.addr, align 8
  %this1 = load %class.C*, %class.C** %this.addr, align 8
  call void @_ZN1CD2Ev(%class.C* %this1) #2
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1BD1Ev(%class.B* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.B*, align 8
  store %class.B* %this, %class.B** %this.addr, align 8
  %this1 = load %class.B*, %class.B** %this.addr, align 8
  call void @_ZN1BD2Ev(%class.B* %this1) #2
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1AD1Ev(%class.A* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.A*, align 8
  store %class.A* %this, %class.A** %this.addr, align 8
  %this1 = load %class.A*, %class.A** %this.addr, align 8
  call void @_ZN1AD2Ev(%class.A* %this1) #2
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1AC2Ev(%class.A* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.A*, align 8
  store %class.A* %this, %class.A** %this.addr, align 8
  %this1 = load %class.A*, %class.A** %this.addr, align 8
  %0 = bitcast %class.A* %this1 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTV1A, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %0, align 8
  %a = getelementptr inbounds %class.A, %class.A* %this1, i32 0, i32 1
  store i32 47, i32* %a, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1A6setIntEi(%class.A* %this, i32 %x) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.A*, align 8
  %x.addr = alloca i32, align 4
  store %class.A* %this, %class.A** %this.addr, align 8
  store i32 %x, i32* %x.addr, align 4
  %this1 = load %class.A*, %class.A** %this.addr, align 8
  %0 = load i32, i32* %x.addr, align 4
  %a = getelementptr inbounds %class.A, %class.A* %this1, i32 0, i32 1
  store i32 %0, i32* %a, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr i32 @_ZN1A6getIntEv(%class.A* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.A*, align 8
  store %class.A* %this, %class.A** %this.addr, align 8
  %this1 = load %class.A*, %class.A** %this.addr, align 8
  %a = getelementptr inbounds %class.A, %class.A* %this1, i32 0, i32 1
  %0 = load i32, i32* %a, align 8
  ret i32 %0
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1BC2Ev(%class.B* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.B*, align 8
  store %class.B* %this, %class.B** %this.addr, align 8
  %this1 = load %class.B*, %class.B** %this.addr, align 8
  %0 = bitcast %class.B* %this1 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTV1B, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %0, align 8
  %b = getelementptr inbounds %class.B, %class.B* %this1, i32 0, i32 1
  store i32 48, i32* %b, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1B6setIntEi(%class.B* %this, i32 %x) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.B*, align 8
  %x.addr = alloca i32, align 4
  store %class.B* %this, %class.B** %this.addr, align 8
  store i32 %x, i32* %x.addr, align 4
  %this1 = load %class.B*, %class.B** %this.addr, align 8
  %0 = load i32, i32* %x.addr, align 4
  %b = getelementptr inbounds %class.B, %class.B* %this1, i32 0, i32 1
  store i32 %0, i32* %b, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr i32 @_ZN1B6getIntEv(%class.B* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.B*, align 8
  store %class.B* %this, %class.B** %this.addr, align 8
  %this1 = load %class.B*, %class.B** %this.addr, align 8
  %b = getelementptr inbounds %class.B, %class.B* %this1, i32 0, i32 1
  %0 = load i32, i32* %b, align 8
  ret i32 %0
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1CC2Ev(%class.C* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.C*, align 8
  store %class.C* %this, %class.C** %this.addr, align 8
  %this1 = load %class.C*, %class.C** %this.addr, align 8
  %0 = bitcast %class.C* %this1 to %class.A*
  call void @_ZN1AC2Ev(%class.A* %0)
  %1 = bitcast %class.C* %this1 to i8*
  %2 = getelementptr inbounds i8, i8* %1, i64 16
  %3 = bitcast i8* %2 to %class.B*
  call void @_ZN1BC2Ev(%class.B* %3)
  %4 = bitcast %class.C* %this1 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*], [4 x i8*] }, { [4 x i8*], [4 x i8*] }* @_ZTV1C, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %4, align 8
  %5 = bitcast %class.C* %this1 to i8*
  %add.ptr = getelementptr inbounds i8, i8* %5, i64 16
  %6 = bitcast i8* %add.ptr to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*], [4 x i8*] }, { [4 x i8*], [4 x i8*] }* @_ZTV1C, i32 0, inrange i32 1, i32 2) to i32 (...)**), i32 (...)*** %6, align 8
  %c = getelementptr inbounds %class.C, %class.C* %this1, i32 0, i32 3
  store i32 49, i32* %c, align 4
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1C6setIntEi(%class.C* %this, i32 %x) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.C*, align 8
  %x.addr = alloca i32, align 4
  store %class.C* %this, %class.C** %this.addr, align 8
  store i32 %x, i32* %x.addr, align 4
  %this1 = load %class.C*, %class.C** %this.addr, align 8
  %0 = load i32, i32* %x.addr, align 4
  %c = getelementptr inbounds %class.C, %class.C* %this1, i32 0, i32 3
  store i32 %0, i32* %c, align 4
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr i32 @_ZN1C6getIntEv(%class.C* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.C*, align 8
  store %class.C* %this, %class.C** %this.addr, align 8
  %this1 = load %class.C*, %class.C** %this.addr, align 8
  %c = getelementptr inbounds %class.C, %class.C* %this1, i32 0, i32 3
  %0 = load i32, i32* %c, align 4
  ret i32 %0
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZThn16_N1C6setIntEi(%class.C* %this, i32 %x) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.C*, align 8
  %x.addr = alloca i32, align 4
  store %class.C* %this, %class.C** %this.addr, align 8
  store i32 %x, i32* %x.addr, align 4
  %this1 = load %class.C*, %class.C** %this.addr, align 8
  %0 = bitcast %class.C* %this1 to i8*
  %1 = getelementptr inbounds i8, i8* %0, i64 -16
  %2 = bitcast i8* %1 to %class.C*
  %3 = load i32, i32* %x.addr, align 4
  tail call void @_ZN1C6setIntEi(%class.C* %2, i32 %3)
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr i32 @_ZThn16_N1C6getIntEv(%class.C* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.C*, align 8
  store %class.C* %this, %class.C** %this.addr, align 8
  %this1 = load %class.C*, %class.C** %this.addr, align 8
  %0 = bitcast %class.C* %this1 to i8*
  %1 = getelementptr inbounds i8, i8* %0, i64 -16
  %2 = bitcast i8* %1 to %class.C*
  %call = tail call i32 @_ZN1C6getIntEv(%class.C* %2)
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1CD2Ev(%class.C* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.C*, align 8
  store %class.C* %this, %class.C** %this.addr, align 8
  %this1 = load %class.C*, %class.C** %this.addr, align 8
  %0 = bitcast %class.C* %this1 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*], [4 x i8*] }, { [4 x i8*], [4 x i8*] }* @_ZTV1C, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %0, align 8
  %1 = bitcast %class.C* %this1 to i8*
  %add.ptr = getelementptr inbounds i8, i8* %1, i64 16
  %2 = bitcast i8* %add.ptr to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*], [4 x i8*] }, { [4 x i8*], [4 x i8*] }* @_ZTV1C, i32 0, inrange i32 1, i32 2) to i32 (...)**), i32 (...)*** %2, align 8
  %c = getelementptr inbounds %class.C, %class.C* %this1, i32 0, i32 3
  store i32 0, i32* %c, align 4
  %3 = bitcast %class.C* %this1 to i8*
  %4 = getelementptr inbounds i8, i8* %3, i64 16
  %5 = bitcast i8* %4 to %class.B*
  call void @_ZN1BD2Ev(%class.B* %5) #2
  %6 = bitcast %class.C* %this1 to %class.A*
  call void @_ZN1AD2Ev(%class.A* %6) #2
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1BD2Ev(%class.B* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.B*, align 8
  store %class.B* %this, %class.B** %this.addr, align 8
  %this1 = load %class.B*, %class.B** %this.addr, align 8
  %0 = bitcast %class.B* %this1 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTV1B, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %0, align 8
  %b = getelementptr inbounds %class.B, %class.B* %this1, i32 0, i32 1
  store i32 0, i32* %b, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN1AD2Ev(%class.A* %this) unnamed_addr #1 comdat align 2 {
entry:
  %this.addr = alloca %class.A*, align 8
  store %class.A* %this, %class.A** %this.addr, align 8
  %this1 = load %class.A*, %class.A** %this.addr, align 8
  %0 = bitcast %class.A* %this1 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTV1A, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %0, align 8
  %a = getelementptr inbounds %class.A, %class.A* %this1, i32 0, i32 1
  store i32 0, i32* %a, align 8
  ret void
}

attributes #0 = { noinline norecurse nounwind optnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { noinline nounwind optnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0-4ubuntu1 "}
